/////////////////////////////////////////////////////////
/////////                                       /////////
/////////  ******            *****************  /////////
/////////   ****              ***************   /////////
/////////    ***               ***         **   /////////
/////////    ***               ***              /////////
/////////    ***               ***     **       /////////
/////////    ***               **********       /////////
/////////    ***               **********       /////////
/////////    ***               ***     **       /////////
/////////    ***               ***              /////////
/////////    ***       **      ***              /////////
/////////   **************    *****             /////////
/////////  ****************  *******            /////////
/////////                                       /////////
/////////////////////////////////////////////////////////
///////  Created by: https://github.com/shaafiee  ///////
///////      Copyright 2020, lottiefiles.com      ///////
/////////////////////////////////////////////////////////

#ifdef EMT
struct alignas(ALIGNSIZE) TransformMatrix {
#else
struct TransformMatrix {
#endif
	struct TransformMatrix* start = NULL;
	struct TransformMatrix* prev = NULL;
	struct TransformMatrix* next = NULL; 
	
	glm::mat4 transform = glm::mat4(1.0f);

	float angle;
	glm::vec3 vector;
	glm::vec3 inverseVector;
	float opacity = -1;

	glm::vec3 translate;
	glm::vec3 scale;
	bool isRotate = false;
	bool isScale = false;
	bool isTranslate = false;
	int startTime = -1;
	int endTime = -1;
} *defaultTransformMatrix = NULL;

#ifdef EMT
struct alignas(ALIGNSIZE) VAOChildren {
#else
struct VAOChildren {
#endif
	struct VAOChildren* start = NULL;
	struct VAOChildren* prev = NULL;
	struct VAOChildren* next = NULL;

	struct VAOList* vaol = NULL;
};

#ifdef EMT
struct alignas(ALIGNSIZE) VAOList {
#else
struct VAOList {
#endif
	struct VAOList* start = NULL;
	struct VAOList* prev = NULL;
	struct VAOList* next = NULL;

	struct CompositeArray* layersComposite = NULL;
	struct CompositeArray* shapesComposite = NULL;

	struct Layers* currentLayers = NULL;
	struct Layers* parentLayers = NULL;
	struct VAOList* parentVAOL = NULL;

	struct VAOChildren* children = NULL;

#ifdef WINDOWS
	#ifdef GLES2
		struct CVAO* vao = NULL;
	#else
		GLuint* vao = NULL;
	#endif
#else
	GLuint *vao = NULL;
#endif
	struct Buffers* associatedBuffers;

	int idxSize;

	int frame;

	bool assigned = false;
	bool instigated = false;

} *boundVAO = NULL;

#ifdef EMT
struct alignas(ALIGNSIZE) BuffersList {
#else
struct BuffersList {
#endif
	struct BuffersList* start = NULL;
	struct BuffersList* prev = NULL;
	struct BuffersList* next = NULL;

	/*
	GLuint *vbo;	
	GLuint *cbo;	
	GLuint *ibo;
	*/

	struct Buffers* buffers_v = NULL;
};

#ifdef EMT
struct alignas(ALIGNSIZE) CompositionList {
#else
struct CompositionList {
#endif
	struct CompositionList* start = NULL;
	struct CompositionList* prev = NULL;
	struct CompositionList* next = NULL;

	struct CompositeArray* composite = NULL;
};

#ifdef EMT
struct alignas(ALIGNSIZE) FrameCompositionRef {
#else
struct FrameCompositionRef {
#endif
	struct FrameCompositionRef* start = NULL;
	struct FrameCompositionRef* prev = NULL;
	struct FrameCompositionRef* next = NULL;

	//struct CompositionList* compositionList = NULL; // removed to change to a VAO-based sequencer
	struct VAOList* vaol = NULL;

	int frame;
} *layersAnimationSequence = NULL, *shapesAnimationSequence = NULL, *animationSequence = NULL;

#ifdef EMT
struct alignas(ALIGNSIZE) CompositeArray {
#else
struct CompositeArray {
#endif
	struct CompositeArray* start = NULL;
	struct CompositeArray* prev = NULL;
	struct CompositeArray* next = NULL;

	struct BuffersList* buffers = NULL;

	//struct VAOList* vaol = NULL; // removed to change to a VAO-based sequencer

	//struct TransformMatrix* position = NULL;
	//struct TransformMatrix* scale = NULL;
	/*
	glm::mat4 position = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);
	glm::mat4 rotate = glm::mat4(1.0f);
	*/

	glm::vec3 positionVec;
	glm::vec3 scaleVec;

	glm::mat4 transform = glm::mat4(1.0f);
	glm::mat4 rotate = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);

	glm::mat4 precomputed = glm::mat4(1.0f);

	glm::vec3 rotateAxisOffset;

	float opacity = 1;

	float rotateAngle = -1;

	int frame = -1;

	bool positionSet = false;
	bool scaleSet = false;
	bool rotateSet = false;
	bool opacitySet = false;

	bool transformSet = false;
	bool isPrecomputed = false;
};

#ifdef EMT
struct alignas(ALIGNSIZE) Transform {
#else
struct Transform {
#endif
	struct TransformAOV* p = NULL;
	struct TransformAOV* r = NULL;
	struct TransformAOV* s = NULL;
	struct TransformAOV* o = NULL;

	struct CompositeArray* composite = NULL;

	int startTime = -1;
	int endTime = -1;

	int maxTime = -1;
	int minTime = -1;

	int startTimeP = -1;
	int endTimeP = -1;
	int startTimeS = -1;
	int endTimeS = -1;
	int startTimeO = -1;
	int endTimeO = -1;
	int startTimeR = -1;
	int endTimeR = -1;

	int frame = -1;
};

#ifdef EMT
struct alignas(ALIGNSIZE) TransformAOV {
#else
struct TransformAOV {
#endif
	struct ArrayOfVertex* v = NULL;
	struct ArrayOfVertex* i = NULL;
	struct ArrayOfVertex* o = NULL;

	struct TransformMatrix* transformMatrix = NULL;

	int startTime = -1;
	int endTime = -1;
	float* frames;
	float* segSize;
	int v_count = 0;
	int bezier_count = 0;
	int s_count;

};

#ifdef EMT
struct alignas(ALIGNSIZE) FillTransformReturn {
#else
struct FillTransformReturn {
#endif
	struct Transform* transform;
	int minTime = -1;
	int maxTime = -1;
} *currentLayersTransformReturn;

struct Vertex* lastPosition;

