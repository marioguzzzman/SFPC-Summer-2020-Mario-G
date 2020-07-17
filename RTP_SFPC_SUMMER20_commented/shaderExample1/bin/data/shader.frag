
uniform float time;
uniform vec2 mouse;


void main()
{
    
    vec2 pos = gl_FragCoord.xy;
    pos.y = 800. - pos.y;

    float dist = distance(pos, mouse);

    // Every pixel runs this code!
    gl_FragColor = vec4(vec3(sin(dist*0.1 - time*3.0) * 0.5 + 0.5), 1.0); // this is saying what the color of the pixel shpuld be
    // it is algo calculating the distance of the olor from the mpuse
    // from each pixel figure out the distance rfrom the mouse
    
    //vec4(vec3(sin(-time*10.0 + dist*0.1)*0.5+0.5), 1.0);

}
