#Andy Le
#Unit 15 Pygame Controls
#ICS4U
#Mr. Trink
#Date Submitted: 15/06/2017

#imports the pygame and serial libraries
import pygame
import serial

#open the serial port for serial communication


#ser = serial.Serial('/dev/ttyUSB0', 9600)
ser = serial.Serial("COM5", 9600)
#initialize the pygame module 
pygame.init()

#function that creates the text object
def text_objects(text, font):

    #renders teh text and returns it in the TextRect
    textSurface = font.render(text, True, white)
    return textSurface, textSurface.get_rect()


#function that displays the text object
def message_display(text):

    #the formatting of the text
    largeText = pygame.font.Font('freesansbold.ttf',115)

    #call the function that renders teh text
    TextSurf, TextRect = text_objects(text, largeText)

    #the area in which text is displayed
    TextRect.center = ((400/2),(300/2))

    #allows for text to be drawn on top of the pygame window
    screen.blit(TextSurf, TextRect)

#displays the pygame window
screen = pygame.display.set_mode((400,300))

#boolean used to check when the user quites the program
done = False

#colours used to reset and display text with every key stroke
black =(0,0,0)
white=(255,255,255)


#print message to acknowlege user that serial communcation has begun
print (ser.readline())

#clock used to refresh the screen when keys pressed
clock = pygame.time.Clock()

while not done:
   
    
    #gets all the keystrokes
    for event in pygame.event.get():

        if event.type ==pygame.QUIT:
            done = True
            
        #resets screen to black after key press
        screen.fill((0,0,0))


#Call these events when the specific keys are pressed down
        if event.type == pygame.KEYDOWN:

            #used for testing
            if event.key == pygame.K_SPACE:
                ser.write(b"32\n")
                print("Space pressed")
                message_display("32")


                #move robot arms
            if event.key == pygame.K_z:

                #sends the serial doe 122 to the arduino
                ser.write(b"122\n")

                #prints messages in the console window
                print(122)
                print("Robot arms down")

                #displays the number in the pygame widnow
                message_display("122")

                #energize the magnets
            if event.key == pygame.K_x:

                #sends the serial code 99 to the arduino
                ser.write(b"99\n")

                #prints the number in the console window
                print(99)
                print("Arms energized")

                #displays the number in the pygame window
                message_display("99")


                #move the robot left
            if event.key == pygame.K_LEFT:

                #sends the serial code 276 to the arduino
                ser.write(b"276\n")
            
                #prints the number in the console window
                print(276)
                print("Robot moving left")

                #displays the number on the pygame window
                message_display("276")
             #move robot right
            if event.key == pygame.K_RIGHT:

                #sends the serial code 275 to the arduino
                ser.write(b"275\n")

                #prints the number in the console window
                print(275)
                print("Robot moving right")

                #displays the number in the pygame window
                message_display("275")
    
            #move robot forward
            if event.key == pygame.K_UP:

                #sends teh serial code 273 to the arduino
                ser.write(b"273\n")

                #prints he number in the console window
                print(273)
                print("Robot moving forward")

                #displays the number on the pygame window
                message_display("273")

            #move robot backward
            if event.key == pygame.K_DOWN:

                #sends serial code 274 to the arduino
                ser.write(b"274\n")

                #prints the number in the console window
                print(274)
                print("Robot moving backward")

                #displays the number on the pygame widnow
                message_display("274")

            #add to pwn value
            if event.key == pygame.K_a:

                #sends serial code 97 to teh arduino
                ser.write(b"97\n")

                #print message in console window
                print(97)
                print("Adding to PWN value")

                #dispalys message on the pygame window
                message_display("97")

                
#subtract from the pwn value
            if event.key == pygame.K_b:

                #sends serial code 97 to teh arduino
                ser.write(b"98\n")

                #print message in console window
                print(98)
                print("Subtracting from the PWN value")

                #dispalys message on the pygame window
                message_display("98")

                
#Call these specfici events when the specfic keys are up after being down
        if event.type == pygame.KEYUP:

            #used for testing
            if event.key == pygame.K_SPACE:
                ser.write(b"32\n")
                print("Space released")
                message_display("32")
                     #move robot arms
        

                #move the robot left
            if event.key == pygame.K_LEFT:
                #sends serial code 276 to arduino
                ser.write(b"276\n")
                
                #print the serial number in console window
                print(276)
                print("Robot stopped")
                
                #display the number on the pygame window
                message_display("276")

             #move robot right
            if event.key == pygame.K_RIGHT:

                #sends serial code 275 to arduino
                ser.write(b"275\n")

                #printn serial number in console window
                print(275)
                print("Robot stopped")
                
                #display the number on the pygame window
                message_display("275")
    
            #move robot forward
            if event.key == pygame.K_UP:

                #sends serial code 273 to arduino
                ser.write(b"273\n")
                print(273)
                print("Robot stopped")

                #display the number on the pygame window
                message_display("273")

            #move robot backward
            if event.key == pygame.K_DOWN:

                #sends serial code 274 to arduino
                ser.write(b"274\n")

                ##prints serial number in console window
                print(274)
                print("Robot stopped")

                #dispalys the number on the pygame window
                message_display("274")

  


        

        

    #used to reset screen after key presses
    pygame.display.flip()
    clock.tick(60)
