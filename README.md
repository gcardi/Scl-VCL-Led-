# Scl-VCL-Led-
A scalable VCL Led Control (component)

The LED is rendered using GDI+ with antialiasing. It has several properties to control the aspect:

 - The bool property "State" for on/off.
 - A TColor property named "TrueColor" to control the color when the led state is "on".
 - A TColor property named "FalseColor" to control the color the when the led state is "off".
 - A TColor property RingColor for the color of the outer ring.
 - A float property RingSizePercent to control the thickness of the outer ring respect the external led's diameter.

The led shine is drawn using a closed path defined using bezier lines aimed to color an irregular area with a gradient with alpha blending.

<img src="docs/assets/images/SclLed1.png" alt="Led-1" border="0"></a>

<img src="docs/assets/images/SclLed2.png" alt="Led-2" border="0"></a>

<img src="docs/assets/images/SclLed3.png" alt="Led-3" border="0"></a>

<img src="docs/assets/images/SclLed4.png" alt="Led-4" border="0"></a>

<img src="docs/assets/images/SclLed5.png" alt="Led-5" border="0"></a>

<img src="docs/assets/images/SclLed6.png" alt="Led-6" border="0"></a>

<img src="docs/assets/images/SclLed7.png" alt="Led-7" border="0"></a>
