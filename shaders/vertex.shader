/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#version 330 core

in vec3                 pos;

uniform mat4            model;
uniform mat4            view;
uniform mat4            proj;

void                    main()
{
    gl_Position = proj * view * model * vec4(pos, 1.0f);
}