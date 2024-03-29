varying vec3 vNormal;
varying vec3 vRefract;
void main() {
    vec4 mPosition = objectMatrix * vec4( position, 1.0 );
    vec4 mvPosition = modelViewMatrix * vec4( position, 1.0 );
    vec3 nWorld = normalize ( mat3( objectMatrix[0].xyz, objectMatrix[1].xyz, objectMatrix[2].xyz ) * normal );
    vNormal = normalize( normalMatrix * normal );
    vec3 I = mPosition.xyz - cameraPosition;
    vRefract = refract( normalize( I ), nWorld, 1.02 );
    gl_Position = projectionMatrix * mvPosition;
}

