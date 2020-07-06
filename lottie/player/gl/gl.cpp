// Shader sources
const GLchar* vertexSource =
    "attribute vec4 position; \n"
    "attribute vec4 color; \n"
    "varying vec4 vcolors; \n"
    "uniform int layersPosition; \n"
    "uniform int shapesPosition; \n"
    "uniform mat4 layersRotate; \n"
    "uniform mat4 shapesRotate; \n"
    "uniform mat4 layersScale; \n"
    "uniform mat4 shapesScale; \n"
    "uniform mat4 layersTransform; \n"
    "uniform mat4 shapesTransform; \n"
    "uniform float objectOpacity; \n"
    "void main() \n"
    "{ \n"
    "  if (shapesPosition == 1 && layersPosition == 1) {\n"
    "    gl_Position = ((layersRotate * shapesRotate) * (layersScale * shapesScale) * (layersTransform * shapesTransform)) * position; \n"
    "  } else if (layersPosition == 1) {\n"
    "    gl_Position = ((layersScale * layersTransform) * layersRotate) * position; \n"
    "  } else if (shapesPosition == 1) {\n"
    "    gl_Position = (shapesRotate * shapesScale * shapesTransform) * position; \n"
    "  } else {\n"
    "    gl_Position = position; \n"
    "  }\n"
    "  vcolors = vec4(color.xyz, objectOpacity); \n"
    "} \n";

const GLchar* fragmentSource =
    "precision mediump float; \n"
    "varying vec4 vcolors; \n"
    "void main() \n"
    "{ \n"
    "  gl_FragColor = vcolors; \n"
    "} \n";


//    "  vcolors = color; \n"
//    "  gl_Position = (layersTransform * shapesTransform) * position; \n"
//    "uniform mat4 shapesTranslate; \n"
//    "uniform mat4 shapesScale; \n"
//    "uniform mat4 shapesRotate; \n"
//    "uniform mat4 layersTranslate; \n"
//    "uniform mat4 layersScale; \n"
//    "uniform mat4 layersRotate; \n"
//    "  gl_Position = (layersScale * layersTranslate * layersRotate) * ((shapesScale * shapesTranslate * shapesRotate) * position); \n"
//    "  gl_Position = ( (shapesScale * layersTranslate) * ((layersScale * layersTranslate) * position) ); \n"
//    "  gl_Position = ((shapesScale * layersScale) * (shapesTranslate * layersTranslate)) * position; \n"
//    "  gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0); \n"
//    "  gl_FragColor = vcolors; \n"
//    "out vec4 FragColor; \n"
//    "precision mediump float; \n"
//    "precision mediump float; \n"

void glInitShaders(int refIndex) {
	GLuint tempShaderProgram;
	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	GLint vertexSuccess = 0;
	GLint fragmentSuccess = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);
	if (vertexSuccess == GL_FALSE) {
		//EM_ASM({console.log("..................> vertex shader failed")});
	}
	if (fragmentSuccess == GL_FALSE) {
		//EM_ASM({console.log("..................> fragment shader failed")});
	}

	// Link the vertex and fragment shader into a shader program
	tempShaderProgram = glCreateProgram();

	glAttachShader(tempShaderProgram, vertexShader);
	glAttachShader(tempShaderProgram, fragmentShader);
	// glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(tempShaderProgram);
	glUseProgram(tempShaderProgram);

	if (refIndex == 0) {
		mainShader = tempShaderProgram;
	} else {
		struct ShaderProgram* passedShaderProgram;
		passedShaderProgram = newShaderProgram();
		passedShaderProgram->shader = &tempShaderProgram;
	}
}

void glInit() {   
	//EM_ASM_({console.log("glinit 1.0 " + $0 + " " + $1 + " " + $2);}, theAnimation->w, theAnimation->h, theAnimation->scaleFactor);
	//SDL_Init(SDL_INIT_VIDEO);

	//EM_ASM_({console.log("glinit 9 " + $0 + " " + $1 + " " + $2);}, theAnimation->w, theAnimation->h, theAnimation->scaleFactor);

	//int* someInt = new int[5000000]();
	//delete[] someInt;
	//wnd = new SDL_Window;
	SDL_Init(SDL_INIT_EVERYTHING);

	int scaledWidth = theAnimation->w;
	int scaledHeight = theAnimation->h;
    
	//EM_ASM_({console.log("glinit 1.0 " + $0 + " " + $1);}, scaledWidth, scaledHeight);

	//wnd = SDL_CreateWindow("lottie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, scaledWidth, scaledHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	//wnd = SDL_CreateWindow("lottie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, scaledWidth, scaledHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	//wnd = new SDL_Window();
	wnd = SDL_CreateWindow("lottie", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, scaledWidth, scaledHeight, 0);


	/*SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);*/

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);

	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1); 

	//EM_ASM({console.log("glinit 1.1");});
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	//EM_ASM({console.log("glinit 1.2");});
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	//EM_ASM({console.log("glinit 1.3");});
	SDL_GL_SetSwapInterval(0);
	//EM_ASM({console.log("glinit 1.4");});
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//EM_ASM({console.log("glinit 1.5");});

	//glEnable(GL_MULTISAMPLE);
	//EM_ASM({console.log("glinit 1.6 " + $0);}, wnd);
	glc = SDL_GL_CreateContext(wnd);

	//EM_ASM({console.log("glinit 1.7");});
	//rdr = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	rdr = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetWindowSize(wnd, theAnimation->w, theAnimation->h);
	SDL_RenderSetLogicalSize(rdr, theAnimation->w, theAnimation->h);
	//SDL_RenderSetScale(rdr, theAnimation->scaleFactorX, theAnimation->scaleFactorY);
	//EM_ASM({console.log("glinit 1.8");});
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

float _xPos = 0;
float _yPos = 0;
float _zPos = 0;
float _translation = false;
float _rotation = false;
int deltaFrame = 0;
/*glm::mat4 trans;
glm::mat4 transShapesP;
glm::mat4 transShapesS;
glm::mat4 transLayersP;
glm::mat4 transLayersS;
glm::mat4 transL;
*/

glm::mat4 lastLayersPosition;
glm::mat4 lastLayersScale;
glm::mat4 lastLayersRotate;
glm::mat4 lastShapesPosition;
glm::mat4 lastShapesScale;
glm::mat4 lastShapesRotate;

bool lastLayersPositionSet = false;
bool lastLayersScaleSet = false;
bool lastLayersRotateSet = false;
bool lastShapesPositionSet = false;
bool lastShapesScaleSet = false;
bool lastShapesRotateSet = false;

bool firstPass = false;
bool secondPass = false;

glm::mat4 identityMatrix = glm::mat4(1.0f);



void glDraw(struct ShaderProgram* passedShaderProgram, struct Buffers* buffersToRender, int frame) {


	if (frame == 0 && firstPass) {
		secondPass = true;
	}

	if (frame == 0 && ! firstPass) {
		firstPass = true;
	}

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT);




		//struct Buffers* tempBuffers = lastBuffersCreated->start;
		if (lastBuffersCreated == NULL) {
			//EM_ASM({console.log("no buffers!");});
			return;
		}
		struct Buffers* tempBuffers = lastBuffersCreated->start->prev;
		struct VAOList* tempVAOL;

		bool buffersExhausted;
		bool firstCycleDone = false;
		bool bogusDone = false;
		int layersPosition = 0;
		int shapesPosition = 0;

		if (passedShaderProgram == NULL) {
			glUseProgram(mainShader);
		} else {
			glUseProgram(*(passedShaderProgram->shader));
		}

		if (frame == 0) {
			tempBuffers->layersTransformSet = false;
			tempBuffers->shapesTransformSet = false;
			tempBuffers->layersScaleSet = false;
			tempBuffers->shapesScaleSet = false;
			tempBuffers->layersRotateSet = false;
			tempBuffers->shapesRotateSet = false;
		}

		bool exhausted = false;
		unsigned int opacityValue = glGetUniformLocation(mainShader, "objectOpacity");
		glUniform1f(opacityValue, 1.0f);
		while (! exhausted) {
			if (! tempBuffers->addedToComposition) {
				glBindVertexArrayOES(*(tempBuffers->vao));
				glDrawElements(GL_TRIANGLES, tempBuffers->idx.size(), GL_UNSIGNED_INT, 0);
				glBindVertexArrayOES(0);
			}

			if (tempBuffers->prev == tempBuffers->start->prev && firstCycleDone) {
				exhausted = true;
			} else {
				tempBuffers = tempBuffers->prev;
			}
			firstCycleDone = true;
		}


		if (frame == 0) {
			if (shapesAnimationSequence != NULL && shapesAnimationSequence->start != NULL) {
				shapesAnimationSequence = shapesAnimationSequence->start;
			}
			if (layersAnimationSequence != NULL && layersAnimationSequence->start != NULL) {
				layersAnimationSequence = layersAnimationSequence->start;
			}
		}

		struct CompositionList* shapesCL = NULL;
		struct CompositionList* layersCL = NULL;
		if (shapesAnimationSequence != NULL && shapesAnimationSequence->compositionList != NULL && shapesAnimationSequence->compositionList->start != NULL) {
			shapesCL = shapesAnimationSequence->compositionList->start->prev;
		}
		if (layersAnimationSequence != NULL && layersAnimationSequence->compositionList != NULL && layersAnimationSequence->compositionList->start != NULL) {
			layersCL = layersAnimationSequence->compositionList->start->prev;
		}

		glm::mat4 lastShapesP = glm::mat4(1.0f);
		glm::mat4 lastShapesS = glm::mat4(1.0f);
		glm::mat4 lastShapesR = glm::mat4(1.0f);
		float lastShapesO;
		glm::mat4 lastLayersP = glm::mat4(1.0f);
		glm::mat4 lastLayersS = glm::mat4(1.0f);
		glm::mat4 lastLayersR = glm::mat4(1.0f);
		float lastLayersO;

		unsigned int layersTransformLoc = glGetUniformLocation(mainShader, "layersTransform");
		unsigned int shapesTransformLoc = glGetUniformLocation(mainShader, "shapesTransform");
		unsigned int layersRotateLoc = glGetUniformLocation(mainShader, "layersRotate");
		unsigned int shapesRotateLoc = glGetUniformLocation(mainShader, "shapesRotate");
		unsigned int layersScaleLoc = glGetUniformLocation(mainShader, "layersScale");
		unsigned int shapesScaleLoc = glGetUniformLocation(mainShader, "shapesScale");

		unsigned int layersPositionLoc = glGetUniformLocation(mainShader, "layersPosition");
		unsigned int shapesPositionLoc = glGetUniformLocation(mainShader, "shapesPosition");

		exhausted = false;
		bool exhaustedShapesCL = false;
		bool exhaustedLayersCL = false;

		struct CompositeArray* currentCA = NULL;
		struct VAOList* currentVAOL = NULL;
		bool caExhausted = false;
		bool vaolExhausted = false;
		bool firstSubCycleDone = false;
		while (! exhausted) {

			lastShapesO = 1.0f;
			lastLayersO = 1.0f;

				//unsigned int opacityValue = glGetUniformLocation(mainShader, "objectOpacity");

						if (layersCL != NULL) {
							lastLayersP = layersCL->composite->transform;
							lastLayersS = layersCL->composite->scale;
							lastLayersR = layersCL->composite->rotate;
							lastLayersO = layersCL->composite->opacity;
						}

						if (shapesCL != NULL) {
							lastShapesP = shapesCL->composite->transform;
							lastShapesS = shapesCL->composite->scale;
							lastShapesR = shapesCL->composite->rotate;
							lastShapesO = shapesCL->composite->opacity;
						}

						glUniformMatrix4fv(shapesTransformLoc, 1, GL_FALSE, glm::value_ptr(lastShapesP));
						glUniformMatrix4fv(layersTransformLoc, 1, GL_FALSE, glm::value_ptr(lastLayersP));
						glUniformMatrix4fv(shapesRotateLoc, 1, GL_FALSE, glm::value_ptr(lastShapesR));
						glUniformMatrix4fv(layersRotateLoc, 1, GL_FALSE, glm::value_ptr(lastLayersR));
						glUniformMatrix4fv(shapesScaleLoc, 1, GL_FALSE, glm::value_ptr(lastShapesS));
						glUniformMatrix4fv(layersScaleLoc, 1, GL_FALSE, glm::value_ptr(lastLayersS));
						if (lastLayersO < lastShapesO) {
							glUniform1f(opacityValue, lastLayersO);
						} else {
							glUniform1f(opacityValue, lastShapesO);
						}
						


			if (shapesCL != NULL && shapesCL->composite != NULL) {
				currentCA = shapesCL->composite->start->prev;

				caExhausted = false;
				firstCycleDone = false;
				while (! caExhausted) {

					if (currentCA->vaol != NULL) {

						currentVAOL = currentCA->vaol->start->prev;
						vaolExhausted = false;
						firstSubCycleDone = false;
						while (! vaolExhausted) {
							glBindVertexArrayOES(*(currentVAOL->vao));
							glDrawElements(GL_TRIANGLES, currentVAOL->idxSize, GL_UNSIGNED_INT, 0);
							glBindVertexArrayOES(0);
							
							if (currentVAOL->prev == currentVAOL->start->prev && firstSubCycleDone) {
								vaolExhausted = true;
							} else {
								currentVAOL = currentVAOL->prev;
							}
							firstSubCycleDone = true;
						}
					}

					if (currentCA->prev == currentCA->start->prev && firstCycleDone) {
						caExhausted = true;
					} else {
						currentCA = currentCA->prev;
					}
					firstCycleDone = true;
				}

			}

			if (layersCL != NULL && layersCL->composite != NULL) {
				currentCA = layersCL->composite->start->prev;

				caExhausted = false;
				firstCycleDone = false;
				while (! caExhausted) {

					if (currentCA->vaol != NULL) {
						EM_ASM({console.log("vaol");});

						currentVAOL = currentCA->vaol->start->prev;
						vaolExhausted = false;
						firstSubCycleDone = false;
						while (! vaolExhausted) {
							glBindVertexArrayOES(*(currentVAOL->vao));
							glDrawElements(GL_TRIANGLES, currentVAOL->idxSize, GL_UNSIGNED_INT, 0);
							glBindVertexArrayOES(0);
							
							if (currentVAOL->prev == currentVAOL->start->prev && firstSubCycleDone) {
								vaolExhausted = true;
							} else {
								currentVAOL = currentVAOL->prev;
							}
							firstSubCycleDone = true;
						}
					}

					if (currentCA->prev == currentCA->start->prev && firstCycleDone) {
						caExhausted = true;
					} else {
						currentCA = currentCA->prev;
					}
					firstCycleDone = true;
				}


			/*
			if ( layersCL->composite->vaol != NULL) {
				EM_ASM({console.log("rendered ");});
				glUniform1i(layersPositionLoc, 1);
				tempVAOL = layersCL->composite->vaol->start->prev;
				buffersExhausted = false;
				firstCycleDone = false;
				while (! buffersExhausted) {
					glBindVertexArrayOES(*(tempVAOL->vao));
					glDrawElements(GL_TRIANGLES, tempVAOL->idxSize, GL_UNSIGNED_INT, 0);
					glBindVertexArrayOES(0);

					if (tempVAOL->prev == tempVAOL->start->prev && firstCycleDone) {
						buffersExhausted = true;
					} else {
						tempVAOL = tempVAOL->prev;
					}
					firstCycleDone = true;
					EM_ASM({console.log("rendered ")});
				}
			}
			*/
			}

			if (exhaustedShapesCL && exhaustedLayersCL) {
				exhausted = true;
			}
			if (shapesCL != NULL && shapesCL->start != NULL && shapesCL->prev != shapesCL->start->prev) {
				shapesCL = shapesCL->prev;
			} else {
				exhaustedShapesCL = true;
			}
			if (layersCL != NULL && layersCL->start != NULL && layersCL->prev != layersCL->start->prev) {
				layersCL = layersCL->prev;
			} else {
				exhaustedLayersCL = true;
			}

		}

		glUseProgram(0);

		if ((layersAnimationSequence == NULL || layersAnimationSequence->next == NULL) && (shapesAnimationSequence == NULL || shapesAnimationSequence->next == NULL)) {
			shapesAnimationSequence = shapesAnimationSequence->start;
			layersAnimationSequence = layersAnimationSequence->start;
			exhausted = true;
		} else {
			if (layersAnimationSequence->next != NULL) {
				layersAnimationSequence = layersAnimationSequence->next;
			}
			if (shapesAnimationSequence->next != NULL) {
				shapesAnimationSequence = shapesAnimationSequence->next;
			}
		}

		return;




}

