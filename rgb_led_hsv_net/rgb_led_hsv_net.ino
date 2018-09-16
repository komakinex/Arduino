#include <Adafruit_NeoPixel.h>

//ピクセル数(LEDの数)
const int numOfPixels = 2;

//WS2812の個数、データ端子に接続したピンの番号、モード
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numOfPixels, 2, NEO_GRB + NEO_KHZ800);

//各ピクセルの明度
float value[numOfPixels];

//現在の番号
int currentNum = 0;


void setup()
{
  //各ピクセルの明度を初期化
  for (int pixelNum = 0; pixelNum<numOfPixels; pixelNum++)
  {
    value[pixelNum] = 0;
  }

  //WS2812をスタート
  pixels.begin();

  //全体の輝度を設定(仮に255で明る過ぎれば小さい値にする)
  pixels.setBrightness(150);
}

void loop()
{
  //各ピクセルをアップデート
  for(int pixelNum=0; pixelNum<numOfPixels; pixelNum++)
  {
    //もしピクセル番号が今と同じなら
    if(pixelNum==currentNum)
    {
      value[pixelNum] = 1;
    }else{
      //明度を減衰させる
      value[pixelNum] *= 0.2;
    }

    //HSVで各ピクセルの色を指定してからRGBに変換
    //色相、彩度、明度
    float hue = 0;
    int red, green, blue;
    HSV_to_RGB(hue, 1.0, value[pixelNum], red, green, blue);

    //ピクセルのRGBをセット
    pixels.setPixelColor(pixelNum, red, green, blue);
  }


  //アップデートしたピクセルの値を送信
  pixels.show();

  //現在の番号を更新(ピクセル数以上になれば０に折り返す)
  currentNum = (currentNum + 1) % numOfPixels;

  //次のループ開始まで25ms待つ
  delay(1000);
}








void HSV_to_RGB(float h, float s, float v, byte *r, byte *g, byte *b)
{
  int i;
  float f,p,q,t;
  
  h = max(0.0, min(360.0, h));
  s = max(0.0, min(100.0, s));
  v = max(0.0, min(100.0, v));
  
  s /= 100;
  v /= 100;
  
  if(s == 0) {
    // Achromatic (grey)
    *r = *g = *b = round(v*255);
    return;
  }

  h /= 60; // sector 0 to 5
  i = floor(h);
  f = h - i; // factorial part of h
  p = v * (1 - s);
  q = v * (1 - s * f);
  t = v * (1 - s * (1 - f));
  switch(i) {
    case 0:
      *r = round(255*v);
      *g = round(255*t);
      *b = round(255*p);
      break;
    case 1:
      *r = round(255*q);
      *g = round(255*v);
      *b = round(255*p);
      break;
    case 2:
      *r = round(255*p);
      *g = round(255*v);
      *b = round(255*t);
      break;
    case 3:
      *r = round(255*p);
      *g = round(255*q);
      *b = round(255*v);
      break;
    case 4:
      *r = round(255*t);
      *g = round(255*p);
      *b = round(255*v);
      break;
    default: // case 5:
      *r = round(255*v);
      *g = round(255*p);
      *b = round(255*q);
    }
}
