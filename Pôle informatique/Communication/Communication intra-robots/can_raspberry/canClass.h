/*! 
 * 	\file canClass.h
 *  \brief     classe de gestion d'un bus can
 *  \details   Cette classe permet d'envoyer et de recevoir des messages via un bus can
 *  \author    Theo RUSINOWITCH <theo.rusinowitch1@etu.univ-lorraine.fr>
 *  \version   4.1a
 *  \date      2021-2022
 */
#if !defined CANCLASS_H
#define CANCLASS_H
#include <thread>
#include <linux/can.h>
#include "logLib.h"
/*!
 * \struct CanResponse_t
 * \brief contient un message décoder venant du bus can
 * \param addr addresse du destinataire du message
 * \param emetteur adresse de l'émeteur du message 
 * \param codeFct code fonction du message
 * \param isRep vrai si c'est une reponse a une requete, faux sinon
 * \param RepId indique le nombre de reponse atendu pour une requete et le num de la reponse pour une reponse
 * \param dataLen frame payload length in byte (0 .. 8) aka data length code
 * \param data CAN frame payload (up to 8 byte)
 */
struct CanResponse_t{
	uint addr;	/* addresse du destinataire du message */
	uint emetteur;	/* adresse de l'éméteur */
	uint codeFct;	/* code fonction du msg */
	bool isRep;	/* vrai si c'est une reponse a une requete, faux sinon */
	uint RepId;	/* nb de rep atendu si requete, num de la rep si reponse */
	uint dataLen;	/* frame payload length in byte (0 .. 8) */
	unsigned char data[8];
}; 




/*!
 *	\class Can
 *  \brief classe qui gère l'envoie et la réception de msg via un bus can
 *  \param s idantifiant du gestionnaire du bus
 *  \param threadListen objet du thread d'écoute du bus can
*/
class Can{
  private:
	int s;
	std::thread* threadListen;
	void listen();
	int traitement_trame(CanResponse_t &rep, can_frame frame);
  public:

	Can() : logC("can") {};
	Log logC;
	int init(uint myAddr);
	bool is_valid_addr(uint addr);
	bool is_valid_code_fct(uint codeFct);
	int send(uint addr, uint codeFct , uint8_t data[], uint data_len, bool isRep, uint repLenght);
	void traitement(CanResponse_t msg);
	int start_listen();
};

    
#endif
