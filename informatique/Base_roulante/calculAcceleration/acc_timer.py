from numpy import append
#import matplotlib.pyplot as plt


PLOT = True
if PLOT :
    import matplotlib.pyplot as plt

#fréquence clock
pclk = 16e6#80e6

#prescaler de la stm
psc = 15#79

#"vrai" prescaler
effective_psc = psc+1
print("APB CLK =", pclk/1e6, "MHz") #pclk1 = 24e6 et pclk2=48e6
print("PSC =", psc)

fclk = pclk / effective_psc # = 1e6
print("fcnt =", fclk/1000,"kHz")

start_freq = 1e3#500 #hz
print("Start Freq =", start_freq, "Hz")

stop_freq = 10e3#5e3
print("Stop Freq =", stop_freq, "Hz")

acc_time = 0.100#0.500 #s
print("acceleration time =", acc_time*1e3, "ms")

def linear_law(t):
    a = (stop_freq - start_freq) / acc_time
    b = start_freq
    return a * t + b

def logistical_law(t):
    from math import exp, log
    # etant donné que nous avons une asymptote, arrête quand on est à k% de la consigne
    k = 0.99 # facteur de correction 
    period = acc_time / (-1 * log((1-k)/k))
    K = (stop_freq - start_freq) # hauteur de la sigmoide
    r = 1 / period # K*r étant la pente au point d'inflexion (pente maxi) de la sigmoide
    t0 = -1 * log((1-k)/k) * period # temps qui correspond à k% de la consigne pour une sigmoide centrée
    offset = K / ( 1 + 1 * exp( r * t0) ) # valeur de la sigmoide centrée à t0 ==> correction à apporter 
    C = start_freq - offset # fréquence de départ à laquelle on retire la correction pour rattraper la correction d'asymptode
    return (K + 2 * offset) / ( 1 + 1 * exp( -r * (t - t0) ) ) + C # on ajoute à K 2x la correction pour rattraper la correction d'asymptote (negtive et positive)


def get_freq_from_time(t):
    # formule d'accélération à utiliser

    #return linear_law(t)  # loi linéaire type ax+b
    return logistical_law(t) # loi sigmoide/logistique en forme de S

def get_period_from_arr(arr):
    return arr/fclk

def get_arr_from_freq(f):
    return fclk/f

arr_table = list()

current_t = 0
#temps = []
while True:

    current_f = get_freq_from_time(current_t)

    if PLOT :
        plt.plot(current_t, current_f, 'r.')

    current_arr = get_arr_from_freq(current_f)

    current_t += get_period_from_arr(current_arr)
    #temps.append(current_t)
    arr_table.append(current_arr)

    if(current_f > stop_freq):
        break


print("uint16_t arr[] = {")
l = len(arr_table)
for i in range(0, l, 20):
    s = "\t"
    for e in arr_table[i: i+20]:
        s+= str(int(e)) + ", "
    print(s)
print("};")
arr_table.reverse()

print("uint16_t rArr[] = {")
for i in range(0, l, 20):
    s = "\t"
    for e in arr_table[i: i+20]:
        s+= str(int(e)) + ", "
    print(s)
print("};")
print ("uint32_t length =", l)



if PLOT:
    plt.xlabel("Temps (s)")
    plt.ylabel("Fréquence (Hz)")
    plt.tight_layout()#True)
    plt.title("Fréquence du signal généré par le timer maître du contrôle moteur lors d'une accélération")
    plt.grid(True)
    plt.show()


    """"
    Tableaux générés pour freq_strat = 1000Hz, freq_end = 10000Hz, acc_time = 0.100ms

    longueur des tableaux = 1105

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
        100, 100, 100, 100, 99
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
        980, 985, 989, 993, 998
};"""