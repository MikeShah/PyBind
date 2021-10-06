# Run with:
#
# (Linux & Mac) python3.5 test.py -m ./mygameengine.so
# (Windows) python3.6 test.py -m ./mygameengine.pyd
#
# The program should also run with 'python2.7' but you will have
# to change the 3.5's to 2.7's in your respective build script as
# well as make sure you compiled with 3.5 or 2.7 load flags.
#
# You will see `python3.5-config --includes` for example which corresponds
# to which version of python you are building.
# (In fact, run `python3.5-config --includes` in the terminal to see what it does!)
import mygameengine

# Now use some python libraries for random numbers!
import random


# Initialize SDL
test = mygameengine.SDLGraphicsProgram(400,400)

# Our main game loop
# Note: This is a simple game that loops for 20 iterations and then
#       exits. 
print("Setting up game loop")
for i in range(0,20):
    # Clear the screen
    test.clear();
    # Generate random coordinates for our box
    x = random.randint(1,400)
    y = random.randint(1,400)
    test.DrawRectangle(x,y,10,10);
    # Add a little delay
    test.delay(100);
    # Refresh the screen
    test.flip();

