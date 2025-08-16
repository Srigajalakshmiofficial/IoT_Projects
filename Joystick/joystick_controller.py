import serial
import pyautogui
import time

arduino = serial.Serial('COM9', 9600)  # Change COM port if needed
time.sleep(2)

print("Ready! Click on your game window to start playing.")

while True:
    data = arduino.readline().decode().strip()
    
    if data == '1':
        pyautogui.press('right')
    elif data == '2':
        pyautogui.press('left')
    elif data == '3':
        pyautogui.press('up')
    elif data == '4':
        pyautogui.press('down')
    elif data == '5':
        pyautogui.press('space')  # Button maps to SPACE key (jump in most games)