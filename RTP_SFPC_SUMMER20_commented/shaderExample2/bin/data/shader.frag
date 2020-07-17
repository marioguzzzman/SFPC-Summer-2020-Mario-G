
uniform float time;
uniform vec2 mouse;
uniform sampler2DRect img; // texture object


void main()
{
    
    
    vec2 pos = gl_FragCoord.xy; // what is our position
    pos.y = 480. - pos.y; // flip it over
    
    
    vec2 pixelPos = pos;
    
    pixelPos.x += 40.0 *  sin(pos.y/100.0 + time); // whats if we alter the position that we are going to grab
   // pixelPos.x = mod( pixelPos.x, 640.0); // mod operators that repeat the image
    //pixelPos.x *= (sin(pos.y*0.1)*0.1 + 1.);
    //pixelPos.x += 70. * sin(time + sin(pixelPos.x*0.1)); // like the slip scan, an offset
    vec3 color = texture2DRect(img, pixelPos).rgb; //grab the color from the texture
//
    float r = color.r;
//
   // pixelPos.x += r*100.0;
   // vec3 color2 = texture2DRect(img, pixelPos).rgb; // take the r value of the pixel and use it to control offset
    
    
    gl_FragColor = vec4(color, 1.0); // pass the color to the pixel
    
    
//    float dist = distance(pos, mouse);
//
//    gl_FragColor = vec4(vec3(sin(-time*10.0 + dist*0.1)*0.5+0.5), 1.0);

}
