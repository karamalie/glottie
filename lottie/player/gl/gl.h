int preSwitch[20]; // to determine the switch of assets to layers (and vice versa)
int currentUniversalCount;
SDL_Window* wnd = NULL;
SDL_Renderer* rdr = NULL;
SDL_GLContext glc;
int lastRefIndex = 0;
GLuint mainShader;

bool redrawRequired = false;
//GLuint* shaderProgram;

struct alignas(ALIGNSIZE) RedrawBuffers {
	struct RedrawBuffers* start;
	struct RedrawBuffers* next;
	struct RedrawBuffers* prev;

	struct Buffers* buffers;
} *redrawList = NULL;

struct alignas(ALIGNSIZE) ShaderProgram {
	struct ShaderProgram* start = NULL;
	struct ShaderProgram* next = NULL;
	struct ShaderProgram* prev = NULL;

	GLuint* shader;
} *lastShaderProgramCreated;

struct alignas(ALIGNSIZE) Buffers {
	struct Buffers* start = NULL;
	struct Buffers* next = NULL;
	struct Buffers* prev = NULL;

	struct Dimensions* dimensions = NULL;

	GLuint* vao = NULL;
	GLuint* vbo = NULL;
	GLuint* cbo = NULL;
	GLuint* ibo = NULL;
	std::vector<unsigned int> idx; // array of triangulation data
	int idxCount;

	GLint* posAttrib = NULL;
	GLint* colAttrib = NULL;
	bool changed = false;
	bool clockwise;
} *lastBuffersCreated;
