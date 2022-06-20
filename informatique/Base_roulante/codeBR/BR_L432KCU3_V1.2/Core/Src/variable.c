/*
 * variable.c
 *
 *  Created on: 8 mai 2022
 *      Author: lucie
 *
 *  Ce fichier répertorie toutes les variables utilisées pour les moteurs (exception des structures, des variables CAN et STM)
 *  Le but est d'avoir le moins de variables "extern" possible dans les fichiers
 *  Pour chaque variable on créer une fonction get_nom_variable() pour pouvoir récupérer sa valeur
 *  Pour la modifier set_nom_variable()
 *  On initialise chaque variable.
 *
 *  Les 2 dernières fonctions get_time_left() et get_freq() ne sont pas optimisées
 *  leurs résultats sont pour un moment précis et pas dans la durée
 *  Mais comme on s'en sert pas c'est pas trop grave, elles sont là au cas où
 *
 *	Ajout de la variable stepSaved et de ses fonctions
 *
 *
 */

#include <stdbool.h>

#include "main.h"
#include "defineMotor.h"
#include "variable.h"

extern TIM_HandleTypeDef htim1;

extern Motor_t motor1;
extern Motor_t motor2;
extern Motor_t motor3;

uint8_t idMsg;

uint32_t arr[] = {
        998, 993, 989, 985, 980, 975, 970, 965, 960, 955, 949, 944, 938, 932, 926, 920, 913, 907, 900, 894,
        887, 880, 873, 866, 859, 852, 844, 837, 829, 822, 814, 806, 799, 791, 783, 775, 767, 760, 752, 744,
        736, 728, 720, 713, 705, 697, 689, 682, 674, 666, 659, 651, 644, 637, 629, 622, 615, 608, 601, 594,
        587, 580, 574, 567, 561, 554, 548, 542, 536, 530, 524, 518, 512, 506, 501, 495, 490, 484, 479, 474,
        469, 464, 459, 454, 449, 445, 440, 435, 431, 427, 422, 418, 414, 410, 406, 402, 398, 394, 390, 387,
        383, 379, 376, 372, 369, 366, 362, 359, 356, 353, 350, 347, 344, 341, 338, 335, 332, 330, 327, 324,
        322, 319, 317, 314, 312, 309, 307, 305, 302, 300, 298, 296, 294, 292, 289, 287, 285, 283, 281, 280,
        278, 276, 274, 272, 270, 269, 267, 265, 263, 262, 260, 258, 257, 255, 254, 252, 251, 249, 248, 246,
        245, 244, 242, 241, 239, 238, 237, 236, 234, 233, 232, 231, 229, 228, 227, 226, 225, 223, 222, 221,
        220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 204, 203, 202,
        201, 200, 199, 198, 198, 197, 196, 195, 194, 194, 193, 192, 191, 191, 190, 189, 188, 188, 187, 186,
        186, 185, 184, 184, 183, 182, 182, 181, 180, 180, 179, 179, 178, 177, 177, 176, 176, 175, 174, 174,
        173, 173, 172, 172, 171, 171, 170, 170, 169, 169, 168, 168, 167, 167, 166, 166, 165, 165, 164, 164,
        163, 163, 162, 162, 162, 161, 161, 160, 160, 159, 159, 159, 158, 158, 157, 157, 157, 156, 156, 155,
        155, 155, 154, 154, 153, 153, 153, 152, 152, 152, 151, 151, 151, 150, 150, 150, 149, 149, 149, 148,
        148, 148, 147, 147, 147, 146, 146, 146, 146, 145, 145, 145, 144, 144, 144, 143, 143, 143, 143, 142,
        142, 142, 142, 141, 141, 141, 140, 140, 140, 140, 139, 139, 139, 139, 138, 138, 138, 138, 137, 137,
        137, 137, 137, 136, 136, 136, 136, 135, 135, 135, 135, 135, 134, 134, 134, 134, 134, 133, 133, 133,
        133, 132, 132, 132, 132, 132, 132, 131, 131, 131, 131, 131, 130, 130, 130, 130, 130, 129, 129, 129,
        129, 129, 129, 128, 128, 128, 128, 128, 128, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126,
        126, 126, 125, 125, 125, 125, 125, 125, 124, 124, 124, 124, 124, 124, 124, 123, 123, 123, 123, 123,
        123, 123, 123, 122, 122, 122, 122, 122, 122, 122, 122, 121, 121, 121, 121, 121, 121, 121, 121, 120,
        120, 120, 120, 120, 120, 120, 120, 119, 119, 119, 119, 119, 119, 119, 119, 119, 118, 118, 118, 118,
        118, 118, 118, 118, 118, 118, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 116, 116, 116, 116,
        116, 116, 116, 116, 116, 116, 116, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 114,
        114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 113, 113, 113, 113, 113, 113, 113, 113,
        113, 113, 113, 113, 113, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
        111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 110, 110, 110, 110,
        110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 109, 109, 109, 109, 109, 109, 109,
        109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 108, 108, 108, 108, 108, 108, 108, 108,
        108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 107,
        107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 106, 106,
        106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106,
        106, 106, 106, 106, 106, 106, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
        105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 104,
        104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104,
        104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 103, 103,
        103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103,
        103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103,
        103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102,
        102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102,
        102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102,
        102, 102, 102, 102, 102, 102, 102, 102, 102, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 99,
};
uint32_t rArr[] = {
        99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
        101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 102, 102, 102, 102,
        102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102,
        102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102,
        102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 103,
        103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103,
        103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103,
        103, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104,
        104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104,
        104, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
        105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 106,
        106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106,
        106, 106, 106, 106, 106, 106, 106, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107,
        107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 108, 108, 108, 108,
        108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 109, 109, 109, 109, 109, 109, 109,
        109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 110, 110, 110, 110, 110, 110, 110, 110,
        110, 110, 110, 110, 110, 110, 110, 110, 110, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,
        111, 111, 111, 111, 111, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
        113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 114, 114, 114, 114, 114, 114, 114,
        114, 114, 114, 114, 114, 114, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 116, 116,
        116, 116, 116, 116, 116, 116, 116, 116, 116, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 118,
        118, 118, 118, 118, 118, 118, 118, 118, 118, 119, 119, 119, 119, 119, 119, 119, 119, 119, 120, 120,
        120, 120, 120, 120, 120, 120, 121, 121, 121, 121, 121, 121, 121, 121, 122, 122, 122, 122, 122, 122,
        122, 122, 123, 123, 123, 123, 123, 123, 123, 123, 124, 124, 124, 124, 124, 124, 124, 125, 125, 125,
        125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 128, 128, 128, 128,
        128, 128, 129, 129, 129, 129, 129, 129, 130, 130, 130, 130, 130, 131, 131, 131, 131, 131, 132, 132,
        132, 132, 132, 132, 133, 133, 133, 133, 134, 134, 134, 134, 134, 135, 135, 135, 135, 135, 136, 136,
        136, 136, 137, 137, 137, 137, 137, 138, 138, 138, 138, 139, 139, 139, 139, 140, 140, 140, 140, 141,
        141, 141, 142, 142, 142, 142, 143, 143, 143, 143, 144, 144, 144, 145, 145, 145, 146, 146, 146, 146,
        147, 147, 147, 148, 148, 148, 149, 149, 149, 150, 150, 150, 151, 151, 151, 152, 152, 152, 153, 153,
        153, 154, 154, 155, 155, 155, 156, 156, 157, 157, 157, 158, 158, 159, 159, 159, 160, 160, 161, 161,
        162, 162, 162, 163, 163, 164, 164, 165, 165, 166, 166, 167, 167, 168, 168, 169, 169, 170, 170, 171,
        171, 172, 172, 173, 173, 174, 174, 175, 176, 176, 177, 177, 178, 179, 179, 180, 180, 181, 182, 182,
        183, 184, 184, 185, 186, 186, 187, 188, 188, 189, 190, 191, 191, 192, 193, 194, 194, 195, 196, 197,
        198, 198, 199, 200, 201, 202, 203, 204, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215,
        216, 217, 218, 219, 220, 221, 222, 223, 225, 226, 227, 228, 229, 231, 232, 233, 234, 236, 237, 238,
        239, 241, 242, 244, 245, 246, 248, 249, 251, 252, 254, 255, 257, 258, 260, 262, 263, 265, 267, 269,
        270, 272, 274, 276, 278, 280, 281, 283, 285, 287, 289, 292, 294, 296, 298, 300, 302, 305, 307, 309,
        312, 314, 317, 319, 322, 324, 327, 330, 332, 335, 338, 341, 344, 347, 350, 353, 356, 359, 362, 366,
        369, 372, 376, 379, 383, 387, 390, 394, 398, 402, 406, 410, 414, 418, 422, 427, 431, 435, 440, 445,
        449, 454, 459, 464, 469, 474, 479, 484, 490, 495, 501, 506, 512, 518, 524, 530, 536, 542, 548, 554,
        561, 567, 574, 580, 587, 594, 601, 608, 615, 622, 629, 637, 644, 651, 659, 666, 674, 682, 689, 697,
        705, 713, 720, 728, 736, 744, 752, 760, 767, 775, 783, 791, 799, 806, 814, 822, 829, 837, 844, 852,
        859, 866, 873, 880, 887, 894, 900, 907, 913, 920, 926, 932, 938, 944, 949, 955, 960, 965, 970, 975,
        980, 985, 989, 993, 998,
};

uint32_t length = LENGTH_ARR_MAX;
uint32_t target = 0;
uint32_t steps = 0;
uint32_t stepsLeft = 0;
Deplacement_State_t deplacementState = ARRET;
uint32_t stepSaved = 0;

/*
 * @brief récupère l'identifiant du message Raspy
 * @param None
 * @retval idMsg
 */
uint8_t get_id_msg(void){
	return idMsg;
}

/*
 * @brief modifie idMsg
 * @param id du message de la Raspy
 * @retval None
 */
void set_id_msg(uint8_t id){
	idMsg = id;
}

/*
 * @brief récupère la longueur des accélèlérations/décélérations
 * @param None
 * @retval lenght
 */
uint32_t get_length(void){
	return length;
}

/*
 * @brief modifie lenght, la longueur des accélèlérations/décélérations
 * @param l longueur
 * @retval None
 */
void set_length(uint32_t l){
	length = l;
}

/*
 * @brief récupère le pointeur du tableau d'accélération
 * @param None
 * @retval arr
 */
uint32_t* get_arr(void){
	return arr;
}

/*
 * @brief récupère le pointeur du tableau de décélèration
 * @param None
 * @retval rArr
 */
uint32_t* get_r_arr(void){
	return rArr;
}

/*
 * @brief récupère l'ARR actuel du timer
 * @param None
 * @retval ARR
 */
uint32_t get_tim_arr(void){
	return htim1.Instance->ARR;
}

/*
 * @brief récupère l'état du déplacement
 * @param None
 * @retval {ARRET}
 * @retval {ACCELERATION}
 * @retval {MAINTIENT}
 * @retval {DECELERATION}
 */
Deplacement_State_t get_deplacement_state(void){
	return deplacementState;
}

/*
 * @brief récupère l'état du déplacement
 * @param {ARRET}
 * @param {ACCELERATION}
 * @param {MAINTIENT}
 * @param {DECELERATION}
 * @retval None
 */
void set_deplacement_state(Deplacement_State_t state){
	deplacementState = state;
}

/*
 * @brief récupère le nombre de pas à effectuer
 * @param None
 * @retval target
 */
uint32_t get_target(void){
	return target;
}

/*
 * @brief modifie le nombre de pas a effectuer
 * @param t nombre de pas a effectuer
 * @retval None
 */
void set_target(uint32_t t){
	target = t;
}

/*
 * @brief réinitialise le nombre de steps effectués
 * @param None
 * @retval None
 */
void reset_steps(void){
	steps = 0;
}

/*
 * @brief incrémente de 1 le nombre de steps effectués
 * @param None
 * @retval None
 */
void count_steps(void){
	steps++;
}

/*
 * @brief récupère le nombre de steps effectués
 * @param None
 * @retval steps
 */
uint32_t get_steps(void){
	return steps;
}

/*
 * @brief récupère le nombre de steps qu'il faut effectuer pouru atteindre le nombre de pas cible
 * @param None
 * @retval stepsLeft
 */
uint32_t get_steps_left(void){
	stepsLeft = get_target() - get_steps();
	return stepsLeft;
}

/*
 * @brief récupère le nombre de steps enregistrés
 * @param None
 * @retval stepSaved
 */
uint32_t get_step_saved(void){
	return stepSaved;
}

/*
 * @brief modifie le nombre de steps enregistrés
 * @param stepSaved
 * @retval None
 */
void set_step_saved(uint32_t s){
	stepSaved = s;
}

/*
 * @brief récupère la fréquence de maintient
 * @param None
 * @retval f
 */
uint32_t get_freq(void){
	uint32_t f = (uint32_t)(CLK) / (uint32_t)(PRESCALER) / (uint32_t)(&htim1.Instance->ARR);
	return f;
}

/*
 * @brief récupère le temps de trajet restant
 * @param None
 * @retval timeLeft
 * ATTENTION ce temps de trajet est basé sur la fréquence actuelle (lors de l'appel de la fonction)
 * ce qui implique que cela ne sera pas le temps exact a cause des phase d'accélèration/décélération
 */
float time_left(void){
	float timeLeft = (float)(get_steps_left()) / (float)(get_freq());
	return timeLeft;
}
