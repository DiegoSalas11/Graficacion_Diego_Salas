#version 430 core



layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform float fTime;
uniform vec3 myLightPosition;
uniform vec3 vEye;



float Dp(float a, float b) 
{

	//return	4*fTime*a*cos(fTime*(a*a)+fTime*(b*b));
	return	-4.0 * a * 0.04 * sin(0.02 * (a*a + b*b) + fTime);
	//return 2*x*(0.02*cos(fTime-0.01*(x*x+z*z))+cos(2*(x*x+z*z))+cos(4*(x*x+z*z))+cos(7*(x*x+z*z)));
}


float F(float x, float z) 
{
	//return 2*sin((fTime*x*x+(z*z*fTime)));
	
	//return 3 * sin(0.01 * (x*x + z*z) + fTime); 
	return 4*sin((x*x+z*z)*0.01-fTime)+(sin(1*(x*x+z*z))/1+(sin(2*(x*x+z*z))/2)+sin(3*(x*x+z*z))/3);
	 
}

vec3 calculateNormal (vec4 v)
{
	vec3 vt1 = vec3(1.0, Dp(v.x, v.z), 0.0);
	vec3 vt2 = vec3(0.0, Dp(v.z, v.x), 1.0);

	return cross (vt1, vt2);
}

void main()
{
vec4 vNewVec = vPosition;
	//calculamos la altura de este vertice
	vNewVec.y = F(vNewVec.x, vNewVec.z);

	//CALCULO DE NORMALES
	vec3 normal = normalize(calculateNormal (vNewVec));
	mat4 matForNormals = transpose(inverse(mTransform));
	vec3 newNormal = normalize(matForNormals * vec4(normal, 1.0)).xyz;

	//calculo de posicion de luz
	vec3 lightv = normalize( myLightPosition - vNewVec.xyz);

	 gl_Position = mTransform * vNewVec;
}