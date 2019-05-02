# The flower mesh
link to the video showcasing it:
https://youtu.be/iAC74iCKpvI

The inspiration came from daffodils, since their petals have this jagged look similar to the effect I was trying to mimic with my mesh.

The mesh is made from triangles that are connected, in a for loop, which can expand and create a flower shape, once the canvas is run the flower keeps growing and growing until closed or when the key “d” is pressed.

The mesh has the following key pressed functions:

‘a’ – makes the flower expand, as when the canvas is first started the root of the flower is small, if you keep holding down the key then it will grow into a flower.

‘s’ – makes the flower smaller.

‘d’ – clears the canvas, so you can start from beginning.

In the ofApp.hpp I have created some variable that will help me create the mesh, such as: ofMesh, ofLight and the variables for the triangles and circles.

In the ofApp.cpp is where all the magic happens, I am using a transformation matrix for the flower to spin around in the direction that I want which in this case is clock-wise;

In the void flower, that I created to store the mesh and all its components, I am setting the colour of the flower, which after a few seconds it changes to a blend of RED or BLUE.

When no key is pressed the flower keeps spinning around in circles, forming random shapes.

What I like to do in order to get the perfect flower shape is to press “a” right when the canvas is started and let it grow then when it gets too big, I clear the canvas by pressing “d” and then I make it smaller again by pressing “s” which makes the flower “grow in reverse” right before your eyes. The video showcases this perfectly.

I am overall happy with how it turned out, as it started as such a simple project which turned out into this complex flower, that’s the beauty of coding you never know what you get, since every day I was changing or adding something to it and in the end it turned into a flower.

