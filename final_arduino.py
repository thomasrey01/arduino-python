import serial           #Import des modules nécessaires
from pygame import mixer
import time

ser = serial.Serial('COM7', baudrate = 9600, timeout = 1) #ser sera l'arduino, cette ligne connecte notre code python avec le circuit arduino
points = 0              #Déclaration de la variable points qui est un entier

def led_off():          #Ceci éteind les lumieres sur l'arduino
    ser.write(b'0')
def correct_answer():   #Ici il allume la lumière verte
    ser.write(b'1')
def wrong_answer():     #Ici il allume la lumière rouge
    ser.write(b'2')

file = 'musique.mp3'    #Import du fichier de musique
mixer.init()
mixer.music.load(file)

def pause_fonc():       #Création d'une fonction qui pause le program
    pause = 0
    while (pause != 1):
        print("Appuyez sur 1 pour continuer")
        pause = int(input())

def chooseQuestion(ligne):  #Création d'une fonction qui choisi la question pour nous
    questions = open(questionsChoix,'r')    #Ici on déclare questions comme le fichier text qui est notre base de donnée
    for i in range(ligne - 1):
        questions.readline()
    print(questions.readline())
    r = int(questions.readline())
    for i in range(4):
        print(questions.readline())
    questions.close()
    return r

print("Bienvenue au quiz!")
print("1- Sport et histoire")
print("2- Géographie et loisirs")
n = 0

                        #Choix de la catégorie
while (n == 0):
    categorie = int(input("Choisissez votre catégorie: "))
    if categorie == 1:
        questionsChoix = 'sport.txt'
        n = 1
        categP = "Sport et Histoire" #categP sera le nom de notre catégorie
    elif categorie == 2:
        questionsChoix = 'geo.txt'
        n = 1
        categP = "Geographie et Loisir"
    else:
        print("Vous n'avez pas choisis une bonne catégorie")


print("Vous avez choisis: ",categP ,"Bonne chance!")

pause_fonc()

print("C'est Parti!")

for i in range(10):     #Loop pour toutes les dix questions
    led_off()
    r = chooseQuestion(i*6 + 1)
    mixer.music.play()  #Début de la musique
    print("Vous avez 10 secondes pour choisir votre réponse!")
    temps = 0
    while (temps != 10): #While loop qui attend la réponse de l'arduino
        arduinoData = 0
        arduinoData = ser.readline()
        temps = temps + 1
        print(temps, "secondes")
        if (arduinoData == b'1\r\n' or arduinoData == b'2\r\n' or arduinoData == b'3\r\n' or arduinoData == b'4\r\n'):  #Fonction if qui regarde si l'utilisateur a répondu à la question 
            temps = 10

    mixer.music.stop()  #Arret de la musique
    
    if (arduinoData == b'1\r\n'):   #Partie qui transforme l'information reçu par l'arduino en nombre entier entre 1 à 4
        reponse = 1
    elif (arduinoData == b'2\r\n'):
        reponse = 2
    elif (arduinoData == b'3\r\n'):
        reponse = 3
    elif (arduinoData == b'4\r\n'):
        reponse = 4
    else:
        reponse = 0
        
    if reponse == r:    #Partie qui vérifie si la réponse donnée est bonne et qui allume le LED par rapport a notre réponse donnée
        print("Bonne réponse!, +1 point!")
        points = points + 1
        correct_answer()
    elif reponse == 0:
        print("Le temps est écoulé!")   #Apres 10 secondes si aucune réponse a été donnée
        wrong_answer()
    else:
        print("Mauvaise réponse!")
        wrong_answer()
    time.sleep(1.5)
    print("Attendez quelques secondes")
    q = 0
    while(q == 0):      #Ceci permet à l'arduino de redonner des valeur nules 
        y = ser.readline()
        if y == b'':
            q = 1
        
    pause_fonc()
    
led_off()
print("C'est FINI! Vous avez: ",points, "/10") #Fin du code, Ceci nous montre le nombre de bonne réponse que nous avons eu
time.sleep(1.5)
if points == 10:
    print("Wow vous avez scoré parfaitement!")
    time.sleep(1.5)
print("Merci d'avoir participé à notre quiz!")
for i in range(10):     #Cette partie crée un flash des LEDs comme petite décoration 
        correct_answer()
        time.sleep(0.2)
        wrong_answer()
        time.sleep(0.2)
led_off()


    
        
        
        
    
