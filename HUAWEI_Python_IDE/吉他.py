import pyttsx3

import time
import random
Fmaj = ["C","G","Em","Am","Fmaj","Dm","Dm7","mini F"]
engine = pyttsx3.init()
j=1
print(" ")
print(" ")
print(" ")
print(" ")
print(" ")
time.sleep(1)
print("Ready go!")
engine.say('Ready...')
engine.runAndWait()
time.sleep(0.6)
engine.say('够')
engine.runAndWait()	
time.sleep(2)

while 1:
    i = random.randint(0,7)
    if i==0:
        engine.say('C')
        print(Fmaj[i])
    elif i==1:
        engine.say('G')
        print(Fmaj[i])
    elif i==2:
        engine.say('E M')
        print(Fmaj[i])
    elif i==3:
        engine.say('A M')
        print(Fmaj[i])
    elif i==4:
        engine.say('F 大 J')
        print(Fmaj[i])
    elif i==5:
        engine.say('D M')
        print(Fmaj[i])
    elif i==6:
        engine.say('D M 7 小横按')
        print(Fmaj[i])
    elif i==7:
        engine.say('小横按 F')
        print(Fmaj[i])
    time.sleep(0.3)
    engine.runAndWait()	
    time.sleep(2.7)