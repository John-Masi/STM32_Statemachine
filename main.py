import serial
import time

mmcu = "STM32F446RE"

ser = serial.Serial(
	port = "/dev/ttyACM0",
	baudrate = 115200,
	timeout = 1,
)

print(f"Established connectection to {mmcu}",)

try:
    while True:
        data = ser.readline()
        if data:
            print("Current State: ", data.decode(errors="replace").strip())

        time.sleep(1)

except KeyboardInterrupt:
    print("\nProgram manually stopped")
except serial.serialutil.SerialException:
    print(f"\nLost connection to {mmcu}")
