
#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_GFX.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_SSD1306.h> //INCLUSÃO DE BIBLIOTECA
 
Adafruit_SSD1306 display = Adafruit_SSD1306(); //OBJETO DO TIPO Adafruit_SSD1306
 
float vout1 = A0; //  connected to analog
float val=0, vall=0;
void setup() {
  Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //INICIALIZA O DISPLAY COM ENDEREÇO I2C 0x3C
 display.setTextColor(WHITE); //DEFINE A COR DO TEXTO
  display.setTextSize(3); //DEFINE O TAMANHO DA FONTE DO TEXTO
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  
display.setTextSize(3); //DEFINE O TAMANHO DA FONTE DO TEXTO
display.setCursor(30,10); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
display.print("DPF"); //ESCREVE O TEXTO NO DISPLAY
display.display(); //EFETIVA A ESCRITA NO DISPLAY
delay(1000);
display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY 
 display.setTextSize(2); //DEFINE O TAMANHO DA FONTE DO TEXTO
display.setCursor(1,10); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
display.print("ELETRONICA"); //ESCREVE O TEXTO NO DISPLAY
display.display(); //EFETIVA A ESCRITA NO DISPLAY
delay(1000);
display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY 
              
}

void loop() {


 vall = analogRead(vout1);  // lê o pino de entrada AD
 
 val=vall*700/970-115;// converte o sinal recebido em leitura pressão
display.setTextSize(1); //DEFINE O TAMANHO DA FONTE DO TEXTO
display.setCursor(20,0); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
display.print("PRESSAO TURBO"); //ESCREVE O TEXTO NO DISPLAY
if(val>5){
display.setTextSize(3); //DEFINE O TAMANHO DA FONTE DO TEXTO
display.setCursor(30,9); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
display.print(val/100); //coverte de KPA para BAR e ESCREVE O TEXTO NO DISPLAY
  display.setTextSize(2); //DEFINE O TAMANHO DA FONTE DO TEXTO
 display.setCursor(val,19); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
display.print("_"); //ESCREVE O TEXTO NO DISPLAY 

display.display(); //EFETIVA A ESCRITA NO DISPLAY
display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
}else{
  display.setTextSize(3); //DEFINE O TAMANHO DA FONTE DO TEXTO
display.setCursor(30,95); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
display.print("0,00"); //ESCREVE O TEXTO NO DISPLAY
display.display(); //EFETIVA A ESCRITA NO DISPLAY
display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY 
}
  }
