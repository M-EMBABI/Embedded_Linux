import os
from gtts import gTTS
import playsound
from time import ctime
import speech_recognition as sr
import webbrowser

r=sr.Recognizer()
def speak(voice_data):
	t=gTTS(text=voice_data,lang='en')
	audio='voice.mp3'
	t.save(audio)
	playsound.playsound(audio)
	print(voice_data)
	os.remove(audio)



def record(ask=False):
    with sr.Microphone(device_index=None) as source:
        r.adjust_for_ambient_noise(source)
        if ask:
            speak(ask)
        audio=r.listen(source)
        voice_data= ''
        try:
            voice_data=r.recognize_google(audio, language="en")
        except sr.UnknownValueError:
            speak("sorry")
        return voice_data.lower()




def responce(voice_data):
    
    if 'name' in voice_data:
        speak(' embabi ')
        
    if 'time' in voice_data or 'hour' in voice_data:
        speak(ctime())

    if 'bye' in voice_data:
        
        speak('bye bye')
        
    if 'open facebook' in voice_data:
        webbrowser.open("www.facebook.com")
        speak('okay')
        
    if  'what is your name':
        speak('my name samrt chat')
    
    
      
while 1:
    voice_data=record()
    responce(voice_data)
