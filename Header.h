
/*Funções Básicas para geração de Formas*/
void DrawHorizontalTracing(float x0, float y0, float width, float height, float increment);
void DrawVerticalTracing(float x0, float y0, float width, float height, float increment);
void DrawRectangleBorder(float x0, float  y0, float width, float height);
void DrawRectangle(float x0, float  y0, float width, float height);
void DrawTrapezoid(float x0, float y0, float big_w, float small_w, float height);
void DrawCircle(float r, float x0, float y0);

/*Funções para Desenhar a Nave*/
void DrawCircle(float r, float x0, float y0);
void DesenhaFumaca(int frame);
void DesenhaNaveHitbox();
void DesenhaNave();
void DesenhaTiro();
void DesenhaAsteroide();

/*Funções de Callback do Teclado*/
void Keyboard(unsigned char key, int x, int y);
void TeclasEspeciais(int key, int x, int y);

/*Funções para Desenhar Elementos na Tela*/
void DesenhaNaveTela();
void DesenhaTiroTela();
void DesenhaAsteroideTela();
void DesenhaLog();
void DesenhaTela(int value);

/*Funções para Monitoramento de Condições*/
int NaveForaTela(float dx, float dy);
void GarbageCollector(int value);

/*Funções de Atualização de Estado do Jogo*/
void AtualizaNave();
void AtualizaTiro();
void AtualizaAsteroid();
void AtualizaEstado(int value);
void CreateAsteroid(int value);

/*Funções Básicas para Operação do Sistema*/
void Inicializar(void);
void Desenha(void);
void Reshape(GLsizei w, GLsizei h);

/*Funções Auxiliares*/
float Radian(float angle);
float Degree(float angle);
unsigned long long currentTimestampMillis();

/*Estruturas de Dados e Funções para Manipulá-las*/
void createElement(element * newElement, float x, float y, int type, float angle);
void inicializar_LE(listElements * entrada);
void apresentar_LE(listElements * entrada);
void addElement_LE(listElements * entrada, float x, float y, int type, float angle);
void copyElement_LE(listElements * destino, listElements * origem);
void popElement_LE(listElements * entrada, float x, float y);
int tamanho_LE(listElements * entrada);
element getElement_LE(listElements * entrada, int i);
void popElementP_LE(listElements * entrada, int p);



