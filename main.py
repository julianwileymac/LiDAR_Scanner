
import serial
import csv

ser = serial.Serial('/dev/ttyUSB0',115200)

#dataFile = open('data.csv', 'w', newline='')
#dataReader = csv.reader(dataFile, csv.QUOTE_ALL)

def turnRight(xStepsR):
	
	stepStr = str(xStepsR) + 'a'

	ser.write(stepStr.encode())

	for i in range(0,xStepsR):

                tempPhi = ser.readline()
		tempTheta = ser.readline() 
		tempDist = ser.readline()

		print(tempPhi)
		print(tempTheta)
		print(tempDist)

def turnLeft(xStepsL):
	
	stepStr = str(xStepsL) + 'b'

	ser.write(stepStr.encode())

	for i in range(0,xStepsL):

		tempPhi = ser.readline()
		tempTheta = ser.readline() 
		tempDist = ser.readline()

		print(tempPhi)
		print(tempTheta)
		print(tempDist)


def tiltUp(yStepsU):
	
	stepStr = str(yStepsU) + 'c'

	ser.write(stepStr.encode())

	for i in range(0,yStepsU):

		tempPhi = ser.readline()
		tempTheta = ser.readline() 
		tempDist = ser.readline()

		print(tempPhi)
		print(tempTheta)
		print(tempDist)


def tiltDown(yStepsD):
	
	stepStr = str(yStepsD) + 'd'

	ser.write(stepStr.encode())

	for i in range(0,yStepsD):

		tempPhi = ser.readline()
		tempTheta = ser.readline() 
		tempDist = ser.readline()

		print(tempPhi)
		print(tempTheta)
		print(tempDist)


def run():
        while True:

                stepDir = input('Type right to turn to the right, left to turn to the left, up to tilt up, or down to tilt down.')
                
                stepd = input('How many steps to the right do you want to turn? integers only please.')
                if stepDir == 'right':
                        turnRight(stepd)
                elif stepDir == 'left':
                        turnLeft(stepd)
                elif stepDir == 'up':
                        tiltUp(stepd)
                elif stepDir == 'down':
                        tiltDown(stepd)
                elif(stepDir == 'stop'):
                        break

if __name__ == '__main__':
        run()
