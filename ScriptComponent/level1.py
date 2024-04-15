# Script that starts up the game engine
print("Starting the level1.py script that loads game objects")

# Create a level/scene
level1 = myengine.GameApp();

print("Now populating game objects")

# Populate with some game objects
# mario_script in the second parameter corresponds to mario_script.py file
# CAREFUL not to name your scripts the same as your game objects, otherwise there will be a namespace clash!
mario = level1.CreateGameObject("Mr. Mario","mario_script")
luigi = level1.CreateGameObject('Mr. Luigi',"luigi_script")

print("Beginning Game Loop")

# Start the level
level1.Loop()
