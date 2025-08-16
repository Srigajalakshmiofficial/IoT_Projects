# Arduino Joystick Controller

A simple Arduino-based joystick controller that converts analog joystick inputs to keyboard commands for PC gaming. This project consists of Arduino code to read joystick values and a Python script to translate those values into keyboard presses.

## Features

- **4-directional movement control** (Up, Down, Left, Right)
- **Button press detection** (mapped to spacebar for jumping)
- **Deadzone implementation** to prevent unwanted inputs
- **Real-time serial communication** between Arduino and PC
- **Customizable key mappings** in Python script

## Hardware Requirements

- Arduino Uno (or compatible board)
- Analog joystick module (with VRX, VRY, and SW pins)
- USB cable for Arduino connection
- Jumper wires for connections

## Wiring Diagram

| Joystick Pin | Arduino Pin |
|-------------|-------------|
| VRX         | A0          |
| VRY         | A1          |
| SW          | Pin 2       |
| VCC         | 5V          |
| GND         | GND         |

## Software Requirements

### Arduino IDE
- Arduino IDE (version 1.8 or later)

### Python Dependencies
```bash
pip install pyserial pyautogui
```

## Installation

1. **Clone or download this project**
2. **Upload Arduino code:**
   - Open `Joystick.ino` in Arduino IDE
   - Select your Arduino board and COM port
   - Upload the code to your Arduino

3. **Set up Python environment:**
   - Install required Python packages: `pip install pyserial pyautogui`
   - Update the COM port in `joystick_controller.py` to match your Arduino's port

## Usage

1. **Connect your Arduino** to your computer via USB
2. **Identify the COM port** your Arduino is using (check Device Manager on Windows)
3. **Update the Python script:**
   ```python
   arduino = serial.Serial('COM9', 9600)  # Change COM9 to your port
   ```
4. **Run the Python controller:**
   ```bash
   python joystick_controller.py
   ```
5. **Click on your game window** and start playing!

## How It Works

### Arduino Code (`Joystick.ino`)
- Reads analog values from joystick X and Y axes
- Implements a deadzone of 200 units around the center position (512)
- Detects button presses using internal pull-up resistor
- Sends directional commands via serial communication:
  - `0` - Neutral position
  - `1` - Right
  - `2` - Left  
  - `3` - Up
  - `4` - Down
  - `5` - Button press

### Python Controller (`joystick_controller.py`)
- Establishes serial communication with Arduino
- Translates numeric commands to keyboard presses:
  - Right/Left/Up/Down arrow keys for movement
  - Spacebar for button press (typically jump in games)

## Customization

### Adjusting Deadzone
In `Joystick.ino`, modify the deadzone value:
```cpp
int deadzone = 200; // Increase for larger deadzone, decrease for smaller
```

### Changing Key Mappings
In `joystick_controller.py`, modify the key mappings:
```python
if data == '1':
    pyautogui.press('d')    # Change 'right' to 'd' for WASD controls
elif data == '2':
    pyautogui.press('a')    # Change 'left' to 'a' for WASD controls
# ... and so on
```

### Adding More Buttons
You can easily extend the code to support additional buttons by:
1. Connecting more buttons to available digital pins
2. Adding button detection in the Arduino code
3. Adding corresponding key mappings in the Python script

## Troubleshooting

### Common Issues

**Arduino not detected:**
- Check USB connection
- Verify correct COM port in Python script
- Ensure Arduino drivers are installed

**No response in games:**
- Make sure the game window is active/focused
- Check if the game supports the keyboard keys you're using
- Verify serial communication is working (check Arduino Serial Monitor)

**Joystick drift:**
- Increase the deadzone value in Arduino code
- Check joystick wiring connections

**Permission errors (Linux/Mac):**
- You may need to run the Python script with sudo
- Or add your user to the dialout group: `sudo usermod -a -G dialout $USER`

## Compatible Games

This controller works with any PC game that accepts keyboard input:
- Platformers (Super Meat Boy, Celeste)
- Retro games (NES/SNES emulators)
- Browser games
- Any game with keyboard controls

## License

This project is open source and available under the MIT License.

## Contributing

Feel free to submit issues, fork the repository, and create pull requests for any improvements.

## Future Enhancements

- Support for multiple joysticks
- Analog input mapping (for gradual movement)
- GUI configuration tool
- Gamepad emulation instead of keyboard mapping
- Wireless connectivity (ESP32/Bluetooth)
