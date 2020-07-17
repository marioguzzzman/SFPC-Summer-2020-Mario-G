
uniform sampler2DRect rockImg;
uniform sampler2DRect lineImg;
uniform float time;



void main()
{
    
    vec2 pos = gl_FragCoord.xy;
    pos.y = 800. - pos.y;
    vec3 color = texture2DRect(rockImg, pos).rgb; // using this image to look for the second vector image
    
    float amt = sin(pos.x*0.01 + time) * 50. + 50.0; // animating the amount over time 
    pos.x += (color.r*2. - 1.0) * amt; // using the r value to control how offset in x I am
// changing the value of amount we can put 100 to look like a spray paint
    pos.y += (color.b*2. - 1.0) * amt; // using the blue value to control how offset in y I am
    
    // use the rock picture to distort  or - the line image
    vec3 color2 = texture2DRect(lineImg, pos).rgb; // second pixel from the line image
    
    
    gl_FragColor = vec4(color2, 1.0);

}
