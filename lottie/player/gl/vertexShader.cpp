const GLchar* vertexSource = 
    "#define counter_0  0\n"
    "#define counter_1  1\n"
    "#define counter_2  2\n"
    "#define counter_3  3\n"
    "#define counter_4  4\n"
    "#define counter_5  5\n"
    "#define counter_6  6\n"
    "#define counter_7  7\n"
    "#define counter_8  8\n"
    "#define counter_9  9\n"
    "#define counter_10  10\n"
    "#define counter_11  11\n"
    "#define counter_12  12\n"
    "#define counter_13  13\n"
    "#define counter_14  14\n"
    "#define counter_15  15\n"
    "#version 140 \n"
    "attribute vec4 position; \n"
    "attribute vec4 color; \n"
    "varying vec4 vcolors; \n"
    "uniform int transformationsCount; \n"
    "uniform int preAnimation; \n"
    "uniform int layersPositionSet[16]; \n"
    "uniform int shapesPositionSet[16]; \n"
    "uniform int layersPositionIncluded[16]; \n"
    "uniform int shapesPositionIncluded[16]; \n"
    "uniform mat4 layersRotate[16]; \n"
    "uniform mat4 shapesRotate[16]; \n"
    "uniform mat4 layersScale[16]; \n"
    "uniform mat4 shapesScale[16]; \n"
    "uniform mat4 layersTransform[16]; \n"
    "uniform mat4 shapesTransform[16]; \n"
    "uniform vec3 layersPosition[16]; \n"
    "uniform vec3 shapesPosition[16]; \n"
    "uniform float objectOpacity[16]; \n"
    "uniform float rotateLayersAngle[16]; \n"
    "uniform vec3 rotateLayersAxisOffset[16]; \n"
    "uniform int rotateLayersAngleSet[16]; \n"
    "uniform float rotateShapesAngle[16]; \n"
    "uniform vec3 rotateShapesAxisOffset[16]; \n"
    "uniform int rotateShapesAngleSet[16]; \n"
    "uniform int instigated[16]; \n"
    "vec4 quat_from_axis_angle(vec3 axis, float angle) \n"
    "{ \n"
    "  vec4 qr; \n"
    "  float half_angle = (angle * 0.5) * 3.14159 / 180.0; \n"
    "  qr.x = axis.x * sin(half_angle); \n"
    "  qr.y = axis.y * sin(half_angle); \n"
    "  qr.z = axis.z * sin(half_angle); \n"
    "  qr.w = cos(half_angle); \n"
    "  return qr; \n"
    "} \n"
    "vec3 rotate_vertex_position(vec3 passedPosition, vec3 axis, float angle) \n"
    "{ \n"
    "  vec4 q = quat_from_axis_angle(axis, angle); \n"
    "  vec3 v = passedPosition.xyz; \n"
    "  return v + 2.0 * cross(q.xyz, cross(q.xyz, v) + q.w * v); \n"
    "} \n"
    "void main() \n"
    "{ \n"
    "  vec4 glpre; \n"
    "  vec4 gltemp; \n"
    "  float tempOpValue = 1.0; \n"
    "  if (preAnimation == 1) { \n"
    "    gl_Position = position; \n"
    "  } else { \n"
    "    gltemp = position; \n"
    "      if (transformationsCount > 0) { \n"
    "        if (instigated[0] == 0) { \n"
    "          if (shapesPositionSet[0] == 1 && layersPositionSet[0] == 1) { \n"
    "            gltemp = shapesRotate[0] * (shapesScale[0] * (shapesTransform[0] * gltemp)); \n"
    "            gltemp = layersRotate[0] * (layersScale[0] * (layersTransform[0] * gltemp)); \n"
    "          } else if (layersPositionSet[0] == 1) {\n"
    "            gltemp = layersRotate[0] * (layersScale[0] * (layersTransform[0] * gltemp)); \n"
    "          } else if (shapesPositionSet[0] == 1) {\n"
    "            gltemp = shapesRotate[0] * (shapesScale[0] * (shapesTransform[0] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[0]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 1) { \n"
    "        if (instigated[1] == 0) { \n"
    "          if (shapesPositionSet[1] == 1 && layersPositionSet[1] == 1) { \n"
    "            gltemp = shapesRotate[1] * (shapesScale[1] * (shapesTransform[1] * gltemp)); \n"
    "            gltemp = layersRotate[1] * (layersScale[1] * (layersTransform[1] * gltemp)); \n"
    "          } else if (layersPositionSet[1] == 1) {\n"
    "            gltemp = layersRotate[1] * (layersScale[1] * (layersTransform[1] * gltemp)); \n"
    "          } else if (shapesPositionSet[1] == 1) {\n"
    "            gltemp = shapesRotate[1] * (shapesScale[1] * (shapesTransform[1] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[1]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 2) { \n"
    "        if (instigated[2] == 0) { \n"
    "          if (shapesPositionSet[2] == 1 && layersPositionSet[2] == 1) { \n"
    "            gltemp = shapesRotate[2] * (shapesScale[2] * (shapesTransform[2] * gltemp)); \n"
    "            gltemp = layersRotate[2] * (layersScale[2] * (layersTransform[2] * gltemp)); \n"
    "          } else if (layersPositionSet[2] == 1) {\n"
    "            gltemp = layersRotate[2] * (layersScale[2] * (layersTransform[2] * gltemp)); \n"
    "          } else if (shapesPositionSet[2] == 1) {\n"
    "            gltemp = shapesRotate[2] * (shapesScale[2] * (shapesTransform[2] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[2]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 3) { \n"
    "        if (instigated[3] == 0) { \n"
    "          if (shapesPositionSet[3] == 1 && layersPositionSet[3] == 1) { \n"
    "            gltemp = shapesRotate[3] * (shapesScale[3] * (shapesTransform[3] * gltemp)); \n"
    "            gltemp = layersRotate[3] * (layersScale[3] * (layersTransform[3] * gltemp)); \n"
    "          } else if (layersPositionSet[3] == 1) {\n"
    "            gltemp = layersRotate[3] * (layersScale[3] * (layersTransform[3] * gltemp)); \n"
    "          } else if (shapesPositionSet[3] == 1) {\n"
    "            gltemp = shapesRotate[3] * (shapesScale[3] * (shapesTransform[3] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[3]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 4) { \n"
    "        if (instigated[4] == 0) { \n"
    "          if (shapesPositionSet[4] == 1 && layersPositionSet[4] == 1) { \n"
    "            gltemp = shapesRotate[4] * (shapesScale[4] * (shapesTransform[4] * gltemp)); \n"
    "            gltemp = layersRotate[4] * (layersScale[4] * (layersTransform[4] * gltemp)); \n"
    "          } else if (layersPositionSet[4] == 1) {\n"
    "            gltemp = layersRotate[4] * (layersScale[4] * (layersTransform[4] * gltemp)); \n"
    "          } else if (shapesPositionSet[4] == 1) {\n"
    "            gltemp = shapesRotate[4] * (shapesScale[4] * (shapesTransform[4] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[4]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 5) { \n"
    "        if (instigated[5] == 0) { \n"
    "          if (shapesPositionSet[5] == 1 && layersPositionSet[5] == 1) { \n"
    "            gltemp = shapesRotate[5] * (shapesScale[5] * (shapesTransform[5] * gltemp)); \n"
    "            gltemp = layersRotate[5] * (layersScale[5] * (layersTransform[5] * gltemp)); \n"
    "          } else if (layersPositionSet[5] == 1) {\n"
    "            gltemp = layersRotate[5] * (layersScale[5] * (layersTransform[5] * gltemp)); \n"
    "          } else if (shapesPositionSet[5] == 1) {\n"
    "            gltemp = shapesRotate[5] * (shapesScale[5] * (shapesTransform[5] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[5]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 6) { \n"
    "        if (instigated[6] == 0) { \n"
    "          if (shapesPositionSet[6] == 1 && layersPositionSet[6] == 1) { \n"
    "            gltemp = shapesRotate[6] * (shapesScale[6] * (shapesTransform[6] * gltemp)); \n"
    "            gltemp = layersRotate[6] * (layersScale[6] * (layersTransform[6] * gltemp)); \n"
    "          } else if (layersPositionSet[6] == 1) {\n"
    "            gltemp = layersRotate[6] * (layersScale[6] * (layersTransform[6] * gltemp)); \n"
    "          } else if (shapesPositionSet[6] == 1) {\n"
    "            gltemp = shapesRotate[6] * (shapesScale[6] * (shapesTransform[6] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[6]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 7) { \n"
    "        if (instigated[7] == 0) { \n"
    "          if (shapesPositionSet[7] == 1 && layersPositionSet[7] == 1) { \n"
    "            gltemp = shapesRotate[7] * (shapesScale[7] * (shapesTransform[7] * gltemp)); \n"
    "            gltemp = layersRotate[7] * (layersScale[7] * (layersTransform[7] * gltemp)); \n"
    "          } else if (layersPositionSet[7] == 1) {\n"
    "            gltemp = layersRotate[7] * (layersScale[7] * (layersTransform[7] * gltemp)); \n"
    "          } else if (shapesPositionSet[7] == 1) {\n"
    "            gltemp = shapesRotate[7] * (shapesScale[7] * (shapesTransform[7] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[7]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 8) { \n"
    "        if (instigated[8] == 0) { \n"
    "          if (shapesPositionSet[8] == 1 && layersPositionSet[8] == 1) { \n"
    "            gltemp = shapesRotate[8] * (shapesScale[8] * (shapesTransform[8] * gltemp)); \n"
    "            gltemp = layersRotate[8] * (layersScale[8] * (layersTransform[8] * gltemp)); \n"
    "          } else if (layersPositionSet[8] == 1) {\n"
    "            gltemp = layersRotate[8] * (layersScale[8] * (layersTransform[8] * gltemp)); \n"
    "          } else if (shapesPositionSet[8] == 1) {\n"
    "            gltemp = shapesRotate[8] * (shapesScale[8] * (shapesTransform[8] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[8]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 9) { \n"
    "        if (instigated[9] == 0) { \n"
    "          if (shapesPositionSet[9] == 1 && layersPositionSet[9] == 1) { \n"
    "            gltemp = shapesRotate[9] * (shapesScale[9] * (shapesTransform[9] * gltemp)); \n"
    "            gltemp = layersRotate[9] * (layersScale[9] * (layersTransform[9] * gltemp)); \n"
    "          } else if (layersPositionSet[9] == 1) {\n"
    "            gltemp = layersRotate[9] * (layersScale[9] * (layersTransform[9] * gltemp)); \n"
    "          } else if (shapesPositionSet[9] == 1) {\n"
    "            gltemp = shapesRotate[9] * (shapesScale[9] * (shapesTransform[9] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[9]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 10) { \n"
    "        if (instigated[10] == 0) { \n"
    "          if (shapesPositionSet[10] == 1 && layersPositionSet[10] == 1) { \n"
    "            gltemp = shapesRotate[10] * (shapesScale[10] * (shapesTransform[10] * gltemp)); \n"
    "            gltemp = layersRotate[10] * (layersScale[10] * (layersTransform[10] * gltemp)); \n"
    "          } else if (layersPositionSet[10] == 1) {\n"
    "            gltemp = layersRotate[10] * (layersScale[10] * (layersTransform[10] * gltemp)); \n"
    "          } else if (shapesPositionSet[10] == 1) {\n"
    "            gltemp = shapesRotate[10] * (shapesScale[10] * (shapesTransform[10] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[10]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 11) { \n"
    "        if (instigated[11] == 0) { \n"
    "          if (shapesPositionSet[11] == 1 && layersPositionSet[11] == 1) { \n"
    "            gltemp = shapesRotate[11] * (shapesScale[11] * (shapesTransform[11] * gltemp)); \n"
    "            gltemp = layersRotate[11] * (layersScale[11] * (layersTransform[11] * gltemp)); \n"
    "          } else if (layersPositionSet[11] == 1) {\n"
    "            gltemp = layersRotate[11] * (layersScale[11] * (layersTransform[11] * gltemp)); \n"
    "          } else if (shapesPositionSet[11] == 1) {\n"
    "            gltemp = shapesRotate[11] * (shapesScale[11] * (shapesTransform[11] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[11]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 12) { \n"
    "        if (instigated[12] == 0) { \n"
    "          if (shapesPositionSet[12] == 1 && layersPositionSet[12] == 1) { \n"
    "            gltemp = shapesRotate[12] * (shapesScale[12] * (shapesTransform[12] * gltemp)); \n"
    "            gltemp = layersRotate[12] * (layersScale[12] * (layersTransform[12] * gltemp)); \n"
    "          } else if (layersPositionSet[12] == 1) {\n"
    "            gltemp = layersRotate[12] * (layersScale[12] * (layersTransform[12] * gltemp)); \n"
    "          } else if (shapesPositionSet[12] == 1) {\n"
    "            gltemp = shapesRotate[12] * (shapesScale[12] * (shapesTransform[12] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[12]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 13) { \n"
    "        if (instigated[13] == 0) { \n"
    "          if (shapesPositionSet[13] == 1 && layersPositionSet[13] == 1) { \n"
    "            gltemp = shapesRotate[13] * (shapesScale[13] * (shapesTransform[13] * gltemp)); \n"
    "            gltemp = layersRotate[13] * (layersScale[13] * (layersTransform[13] * gltemp)); \n"
    "          } else if (layersPositionSet[13] == 1) {\n"
    "            gltemp = layersRotate[13] * (layersScale[13] * (layersTransform[13] * gltemp)); \n"
    "          } else if (shapesPositionSet[13] == 1) {\n"
    "            gltemp = shapesRotate[13] * (shapesScale[13] * (shapesTransform[13] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[13]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 14) { \n"
    "        if (instigated[14] == 0) { \n"
    "          if (shapesPositionSet[14] == 1 && layersPositionSet[14] == 1) { \n"
    "            gltemp = shapesRotate[14] * (shapesScale[14] * (shapesTransform[14] * gltemp)); \n"
    "            gltemp = layersRotate[14] * (layersScale[14] * (layersTransform[14] * gltemp)); \n"
    "          } else if (layersPositionSet[14] == 1) {\n"
    "            gltemp = layersRotate[14] * (layersScale[14] * (layersTransform[14] * gltemp)); \n"
    "          } else if (shapesPositionSet[14] == 1) {\n"
    "            gltemp = shapesRotate[14] * (shapesScale[14] * (shapesTransform[14] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[14]; \n"
    "        } \n"
    "      } \n"
    "      if (transformationsCount > 15) { \n"
    "        if (instigated[15] == 0) { \n"
    "          if (shapesPositionSet[15] == 1 && layersPositionSet[15] == 1) { \n"
    "            gltemp = shapesRotate[15] * (shapesScale[15] * (shapesTransform[15] * gltemp)); \n"
    "            gltemp = layersRotate[15] * (layersScale[15] * (layersTransform[15] * gltemp)); \n"
    "          } else if (layersPositionSet[15] == 1) {\n"
    "            gltemp = layersRotate[15] * (layersScale[15] * (layersTransform[15] * gltemp)); \n"
    "          } else if (shapesPositionSet[15] == 1) {\n"
    "            gltemp = shapesRotate[15] * (shapesScale[15] * (shapesTransform[15] * gltemp)); \n"
    "          } \n"
    "          tempOpValue = objectOpacity[15]; \n"
    "        } \n"
    "      } \n"
    "    gl_Position = gltemp; \n"
    "  } \n"
    "    if (tempOpValue > 1.0) { \n"
    "      tempOpValue = 1.0; \n"
    "    } \n"
    "    vcolors = vec4(color.xyz, tempOpValue); \n"
    "} \n";