#include <bits/stdc++.h>
#include "bmplib.cpp"
#include <vector>
using namespace std;
unsigned char image[SIZE][SIZE][RGB];
void edges();
void DandL();
void rotate();
void flip();
void merge();
void invert();
void BlackandWhite();
void loadImage();
void saveImage();
void enlarge();
void Blur();
void shrink();
void mirror();
void crop();
void shuffle();
void skewV();
void skewH();
void Show_Menu(int ch = 0,int chh=0)
{

  if(!chh)loadImage();

  if (ch == 1)
  {
    BlackandWhite();
  }
  else if (ch == 2)
  {
    invert();
  }
  else if (ch == 3)
  {
    merge();
  }
  else if (ch == 4)
  {
    flip();
  }
  else if (ch == 5)
  {
    rotate();
  }
  else if (ch == 6)
  {
    DandL();
  }
  else if (ch == 7)
  {
    edges();
  }
  else if (ch == 8)
  {
    enlarge();
  }
  else if (ch == 9)
  {
    shrink();
  }
  else if (ch == 10)
  {
    mirror();
  }
  else if (ch == 11)
  {
    shuffle();
  }
  else if (ch == 12)
  {
    Blur();
  }
  else if (ch == 13)
  {
    crop();
  }
  else if (ch == 14)
  {
    skewV();
  }
  else if (ch == 15)
  {
    skewH();
  }
  else if (ch == 16)
  {
    saveImage();
  }
}
void flip()
{
  cout << "Type \'H\' For Horizontal and \'V\' for Vertical" << endl
       << endl;
start:;
  string choice;
  cin >> choice;
  if (choice == "v" || choice == "V")
  {
    for (int i = 0, j = 255; i <= j; i++, j--)
    {
      for (int q = 0; q < 255; q++)
      {
        swap(image[i][q][0], image[j][q][0]);
        
        swap(image[i][q][1], image[j][q][1]);
        
        swap(image[i][q][2], image[j][q][2]);
      }
    }
  }
  else if (choice == "h" || choice == "H")
  {
    for (int i = 0, j = 255; i <= j; i++, j--)
    {
      for (int r = 0; r < 255; r++)
      {
        swap(image[r][i][0], image[r][j][0]);
      
        swap(image[r][i][1], image[r][j][1]);
        swap(image[r][i][2], image[r][j][2]);
      }
    }
  }
  else
  {
    cout << "invaild input, please enter either \'V\' or \'h\'" << endl;

    goto start;
  }

  //saveImage();
}
void BlackandWhite()
{
  int avg = 128;

  for (int i = 0; i < 256; i++)
    for (int j = 0; j < 256; j++)
    {
   if((image[i][j][0]+image[i][j][1]+image[i][j][2])/3>=128)image[i][j][0]=255,image[i][j][1]=255,image[i][j][2]=255;
   else image[i][j][0]=0,image[i][j][1]=0,image[i][j][2]=0;
    }
  //saveImage();
}
void invert()
{
  for (int i = 0; i < 256; i++)
    for (int j = 0; j < 256; j++)
    {
      image[i][j][0] = 255 - image[i][j][0];
      image[i][j][1] = 255 - image[i][j][1];
      image[i][j][2] = 255 - image[i][j][2];
    }
//  saveImage();
}
void merge()
{
  unsigned char second[SIZE][SIZE][RGB];
  char imageFileName[100];

  // Get gray scale image file name
  cout << "Enter the source of the image file you want to merge with: ";
  cin >> imageFileName;

  // Add to it .bmp extension and load image
  strcat(imageFileName, ".bmp");
  readRGBBMP(imageFileName, second);

  for (int i = 0; i < 256; i++)
    for (int j = 0; j < 256; j++)
    {
      image[i][j][0] = (image[i][j][0] + second[i][j][0]) / 2;
      
      image[i][j][1] = (image[i][j][1] + second[i][j][1]) / 2;
      
      image[i][j][2] = (image[i][j][2] + second[i][j][2]) / 2;
    }
 // saveImage();
}
void rotate()
{
  unsigned char temp[SIZE][SIZE][RGB];
  cout << "Choose from 90 or 180 or 270" << endl
       << endl;
       start:;
  int c;
  cin >> c;
  if (c == 90)
  {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j < 256; j++)
      {
        temp[j][255 - i][0] = image[i][j][0];
        temp[j][255 - i][1] = image[i][j][1];
        temp[j][255 - i][2] = image[i][j][2];
      }
    // char imageFileName[100];

    // // Get gray scale image target file name
    // cout << "Enter the target image file name: ";
    // cin >> imageFileName;

    // // Add to it .bmp extension and load image
    // strcat(imageFileName, ".bmp");
    // writeRGBBMP(imageFileName, temp);

  }
  else if (c == 180)
  {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j < 256; j++)
      {
        temp[i][j][0] = image[255 - i][255 - j][0];
        temp[i][j][1] = image[255 - i][255 - j][1];
        temp[i][j][2] = image[255 - i][255 - j][2];

      }
    // char imageFileName[100];

    // // Get gray scale image target file name
    // cout << "Enter the target image file name: ";
    // cin >> imageFileName;

    // // Add to it .bmp extension and load image
    // strcat(imageFileName, ".bmp");
    // writeRGBBMP(imageFileName, temp);
  }
  else if (c == 270)
  {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j < 256; j++)
      {
        temp[255 - j][i][0] = image[i][j][0];
        temp[255 - j][i][1] = image[i][j][1];
        temp[255 - j][i][2] = image[i][j][2];
      
      }
    // char imageFileName[100];

    // // Get gray scale image target file name
    // cout << "Enter the target image file name: ";
    // cin >> imageFileName;

    // // Add to it .bmp extension and load image
    // strcat(imageFileName, ".bmp");
    // writeRGBBMP(imageFileName, temp);
  }
  else{
    cout<<"invalid number, please enter a value berween \" 90, 180, 270 \"\n";
    goto start;
  }
  for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=temp[i][j][q];
     }
     }
  }
}
void DandL()
{
  cout << "Choose from B or W" << endl
       << endl;
       start:;
  char x;
  cin >> x;
  if(tolower(x)=='b'||tolower(x)=='w')
  cout << "Please, Enter the percentage of " << x << endl;
  else{
    cout<<"invalid input, please enter B for darken and W for lighten the image\n";
    goto start;
  }
  int per;
  start2:;
  cin >> per;
  if(per>100||per<0){
    cout<<"invalid percentage, please enter a percentage between 0 to 100 iclusive\n";
    goto start2;
  }
  if (tolower(x) == 'w')
  {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j < 256; j++)
      {
      image[i][j][0] = ((image[i][j][0] + (image[i][j][0] * (per / 100.0))) > 255) ? 255 : image[i][j][0] + (image[i][j][0] * (per / 100.0));
      image[i][j][1] = ((image[i][j][1] + (image[i][j][1] * (per / 100.0))) > 255) ? 255 : image[i][j][1] + (image[i][j][1] * (per / 100.0));
      image[i][j][2] = ((image[i][j][2] + (image[i][j][2] * (per / 100.0))) > 255) ? 255 : image[i][j][2] + (image[i][j][2] * (per / 100.0));
      }
   // saveImage();
  }
  else if (tolower(x) == 'b')
  {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j < 256; j++)
      {
        image[i][j][0] = image[i][j][0] - (image[i][j][0] * (per / 100.0));
        image[i][j][1] = image[i][j][1] - (image[i][j][1] * (per / 100.0));
        image[i][j][2] = image[i][j][2] - (image[i][j][2] * (per / 100.0));
      }
    //saveImage();
  }
}
int arr[] = {1, 0, -1, 0, 1, 1, -1, 1};
int arr2[] = {0, 1, 0, -1, 1, -1, 1, -1};
bool ok(int a, int b)
{
  return !(a < 0 && a > 255 && b < 0 && b > 255);
}

void edges()
{
 // unsigned char second[SIZE][SIZE][RGB];
  unsigned char su[SIZE][SIZE];
  unsigned char su2[SIZE][SIZE];
  for (int i = 0; i < 256; i++)
  {
    for (int j = 0; j < 256; j++)
    {
  su[i][j]=(image[i][j][0]+image[i][j][1]+image[i][j][2])/3;
  su2[i][j]=su[i][j];
    }
  }
   
  for (int i = 0; i < 256; i++)
  {
    for (int j = 0; j < 256; j++)
    {
 if(su[i][j]<=128)su[i][j]=0;
 else su[i][j]=255; 
 su2[i][j]=su[i][j];
   }
  }
 
for(int i=0;i<256;i++){
  for(int j=0;j<256;j++){
int sum = 0;
      int y = 0;
      for (int q = 0; q < 8; q++)
      {
        int a = i + arr[q], b = j + arr2[q];

        if (ok(a, b))
        {
          y++;
          if (su2[i][j] == su2[a][b])
          {
            sum++;
          }
        }
      }
      if (sum == y)
      {
        su[i][j] = 255;
      }
      else
      {
        su[i][j] = 50;
      }
}
  }

     

    for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=su[i][j];
     }
     }
  }
  };
void enlarge()
{
  unsigned char temp[SIZE][SIZE][RGB];
  string choice;

  cout << "Kindly, Choose the number of quarter that you want to enlarge\n";
  // start:;
  cout << " ----------------------------------------------------------------------\n"
       << "|           /|                  |                 _                  |\n"
       << "|            |                  |                / \\                 |\n"
       << "|            |                  |                  /                 |\n"
       << "|           |                 |                /_                |\n"
       << "----------------------------------------------------------------------\n"
       << "|            __                 |               |      |             |\n"
       << "|           /  \\                |               |______|             |\n"
       << "|           ___/                |                      |             |\n"
       << "|              \\                |                      |             |\n"
       << "|           ___/                |                      |             | \n"
       << "----------------------------------------------------------------------  \n";

  cin >> choice;

  int x = 0;
  bool flag = true;
  for (int i = 0; i < choice.size(); i++)
  {
    if (isalpha(choice[i]))
    {
      flag = 0;
      break;
    }
    else
    {
      x *= 10;
      x += choice[i] - '0';
    }
  }
  if (x < 1 || x > 4)
    flag = false;
  while (!flag)
  {
    flag = true;
    x = 0;
    cout << "Your input is invalid \n"
         << "Please, Enter a valid number \'between 1 to 4 inclusive \'" << endl;
    //    goto start;
    cout << "-----------------------------------------------------------------------\n"
         << "|           /|                  |                 _                  |\n"
         << "|            |                  |                / \\                 |\n"
         << "|            |                  |                  /                 |\n"
         << "|           |                 |                /_                |\n"
         << "----------------------------------------------------------------------\n"
         << "|            __                 |               |      |             |\n"
         << "|           /  \\                |               |______|             |\n"
         << "|           ___/                |                      |             |\n"
         << "|              \\                |                      |             |\n"
         << "|           ___/                |                      |             | \n"
         << "----------------------------------------------------------------------  \n";

    cin >> choice;
    for (int i = 0; i < choice.size(); i++)
    {
      if (isalpha(choice[i]))
      {
        flag = 0;
        break;
      }
      else
      {
        // flag=true;
        x *= 10;
        x += choice[i] - '0';
      }
    }
    if (!(x <= 4 && x >= 1))
    {
      flag = false;
    }
  }
  int b1{}, b2{}, b3{}, b4;
  if (x == 1)
  {
    b1 = 0;
    b2 = 128;
    b3 = 0;
    b4 = 128;
  }
  else if (x == 2)
  {
    b1 = 0;
    b2 = 128;
    b3 = 128;
    b4 = 256;
  }
  else if (x == 3)
  {
    b1 = 128;
    b2 = 256;
    b3 = 0;
    b4 = 128;
  }
  else if (x == 4)
  {
    b1 = 128;
    b2 = 256;
    b3 = 128;
    b4 = 256;
  }

  int i = 0;
  for (int r = b1; r < b2; ++r)
  {
    int j = 0;
    for (int c = b3; c < b4; ++c)
    {
      temp[i][j][0] = image[r][c][0];
temp[i][j][1] = image[r][c][1];
temp[i][j][2] = image[r][c][2];

      temp[i][j + 1][0] = image[r][c][0];
temp[i][j + 1][1] = image[r][c][1];
temp[i][j + 1][2] = image[r][c][2];

      temp[i + 1][j][0] = image[r][c][0];
temp[i + 1][j][1] = image[r][c][1];
temp[i + 1][j][2] = image[r][c][2];

      temp[i + 1][j + 1][0] = image[r][c][0];
temp[i + 1][j + 1][1] = image[r][c][1];
temp[i + 1][j + 1][2] = image[r][c][2];


      j += 2;
    }
    i += 2;
  }

  for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=temp[i][j][q];
     }
     }
  }}
void Blur()
{
  cout << "We need the strength of the blur:\n "
       << "For low blur please, Enter number 1\n"
       << "For medium blur please, Enter number 2\n"
       << "And for high blur please, Enter number 3\n";
  int x;
  cin >> x;
  while (!(x >= 1 && x <= 3))
  {
    cout << "Invalid number \n"
         << "Please, Enter number between 1 to 3 inclusive\n";
    cin >> x;
  }
  unsigned char temp[SIZE][SIZE][RGB];
  int KS;
  if (x == 1)
  {
    KS = 3;
  }
  else if (x == 2)
  {
    KS = 5;
  }
  else if (x == 3)
  {
    KS = 10;
  }
  for (int i = 0; i < 256; i++)
  {
    for (int j = 0; j < 256; j++)
    {
      int sum = 0,sum1=0,sum2=0;
      for (int x = -KS / 2; x <= KS / 2; x++)
      {
        for (int y = -KS / 2; y <= KS / 2; y++)
        {
          sum += image[i + x][j + y][0];
          sum1 += image[i + x][j + y][1];
          sum2 += image[i + x][j + y][2];
        }
      }
      temp[i][j][0] = (sum / (pow(KS, 2)));
      temp[i][j][1] = (sum1 / (pow(KS, 2)));
      temp[i][j][2] = (sum2 / (pow(KS, 2)));
    }
  }

  for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=temp[i][j][q];
     }
     }
  }}
void mirror()
{
  start:;
  cout << "Kindly, Enter a character refers to the half which you want to make a mirror to it, r for right, u for up, d for down, l for left\n"  << endl;
  char c;
  
  cin >> c;
  if(!(tolower (c)=='r'||tolower(c)=='l'||tolower(c)=='u'||tolower(c)=='d')){
  cout<<"invalid input.\n";
    goto start;
    
  }
  int x, y, z, w;
  if (tolower(c) == 'r')
  {
    for (int i = 0, j = 255; i <= j; i++, j--)
    {
      for (int q = 0; q < 255; q++)
      {
        image[q][i][0] = image[q][j][0];
        image[q][i][1] = image[q][j][1];
        image[q][i][2] = image[q][j][2];
      }
    }
  }
  else if (tolower(c) == 'l')
  {
    for (int i = 0, j = 255; i <= j; i++, j--)
    {
      for (int q = 0; q < 255; q++)
      {
        image[q][j][0] = image[q][i][0];
        image[q][j][1] = image[q][i][1];
        image[q][j][2] = image[q][i][2];
      }
    }
  }
  else if (tolower(c) == 'u')
  {
    for (int i = 0, j = 255; i <= j; i++, j--)
    {
      for (int q = 0; q < 255; q++)
      {
        image[j][q][0] = image[i][q][0];
        image[j][q][1] = image[i][q][1];
        image[j][q][2] = image[i][q][2];
      }
    }
  }
  else if (tolower(c) == 'd')
  {
    for (int i = 0, j = 255; i <= j; i++, j--)
    {
      for (int q = 0; q < 255; q++)
      {
        image[i][q][0] = image[j][q][0];
        image[i][q][1] = image[j][q][1];
        image[i][q][2] = image[j][q][2];
      }
    }
  }
  //saveImage();
}
void shrink()
{
  cout << "To shrink image dimensions to "
       << "\n"
       << "1/2 Press 1"
       << "\n"
       << "1/3 Press 2"
       << "\n"
       << "1/4 Press 3"
       << "\n";
  int x;
  start:;
  cin >> x;

  if(!(x==1||x==2||x==3)){
    cout<<"invalid number. please, enter \'1, 2, 3\'\n";
    goto start;
  }
  unsigned char temp[SIZE][SIZE][RGB] = {255};
  int arr[SIZE][SIZE] = {0};
  if (x == 1)
  {
    int i{};
    for (int r = 0; r < 128; ++r)
    {
      int j{};
      for (int c = 0; c < 128; ++c)
      {
        int avg1 = ((image[i][j][0] + image[i + 1][j][0] + image[i][j + 1][0] + image[i + 1][j + 1][0]) / 4);
        int avg2 = ((image[i][j][1] + image[i + 1][j][1] + image[i][j + 1][1] + image[i + 1][j + 1][1]) / 4);
        int avg3 = ((image[i][j][2] + image[i + 1][j][2] + image[i][j + 1][2] + image[i + 1][j + 1][2]) / 4);
        temp[r][c][0] = avg1;
        temp[r][c][1] = avg2;
        temp[r][c][2] = avg3;
        arr[r][c] = 1;
        j += 2;
      }
      i += 2;
    }
  }
  else if (x == 2)
  {
    int i{};
    for (int r = 0; r < 86; ++r)
    {
      int j{};
      for (int c = 0; c < 86; ++c)
      {
        int avg = ((image[i][j][0] + image[i + 1][j][0] + image[i + 2][j + 1][0] + image[i][j + 1][0] + image[i][j + 2][0] + image[i + 1][j + 2][0]) / 6);
        int avg1 = ((image[i][j][1] + image[i + 1][j][1] + image[i + 2][j + 1][1] + image[i][j + 1][1] + image[i][j + 2][1] + image[i + 1][j + 2][1]) / 6);
        int avg2 = ((image[i][j][2] + image[i + 1][j][2] + image[i + 2][j + 1][2] + image[i][j + 1][2] + image[i][j + 2][2] + image[i + 1][j + 2][2]) / 6);
        temp[r][c][0] = avg;
        temp[r][c][1] = avg1;
        temp[r][c][2] = avg2;
        arr[r][c] = 1;
        j += 3;
      }
      i += 3;
    }
  }
  else if (x == 3)
  {
    int i{};
    for (int r = 0; r < 64; ++r)
    {
      int j{};
      for (int c = 0; c < 64; ++c)
      {
        int avg = ((image[i][j][0] + image[i][j + 1][0] + image[i][j + 2][0] + image[i + 1][j][0] + image[i + 1][j + 1][0] + image[i + 2][j][0] + image[i + 2][j + 1][0] + image[i + 2][j + 2][0]) / 8);
        int avg1 = ((image[i][j][1] + image[i][j + 1][1] + image[i][j + 2][1] + image[i + 1][j][1] + image[i + 1][j + 1][1] + image[i + 2][j][1] + image[i + 2][j + 1][1] + image[i + 2][j + 2][1]) / 8);
        int avg2 = ((image[i][j][2] + image[i][j + 1][2] + image[i][j + 2][2] + image[i + 1][j][2] + image[i + 1][j + 1][2] + image[i + 2][j][2] + image[i + 2][j + 1][2] + image[i + 2][j + 2][2]) / 8);
        temp[r][c][0] = avg;
        temp[r][c][1] = avg1;
        temp[r][c][2] = avg2;
        arr[r][c] = 1;
        j += 4;
      }
      i += 4;
    }
  }
  for (int j = 0; j < SIZE; ++j)
  {
    for (int k = 0; k < SIZE; ++k)
    {
      if (!arr[j][k])
      {
        temp[j][k][0] = 255;
        temp[j][k][1] = 255;
        temp[j][k][2] = 255;
      }
    }
  }
   for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=temp[i][j][q];
     }
     }
  }
};
void crop()
{
  int x, y, w, l;
  int arr[SIZE][SIZE] = {0};
  cout << "We need four integers (to determine the corners of the rectangel which you want to crop ) \n";
  cout << "Kindely, Enter x position: \n";
  start:;
  cin >> x;
  if(x<0||x>255){
    cout<<"invalid input, enter a number between 0 to 255 inclusive\n";
    goto start;
  }
  cout << "Kindely, Enter y position: \n";
  start2:;
  cin >> y;
  if(y<0||y>255){
    cout<<"invalid input, enter a number between 0 to 255 inclusive\n";
    goto start2;
  }
  cout << "Please, Enter the length: \n";
  start3:;
  cin >> l;
  if(y+l<x){
    cout<<"invalid input, length must be positive\n";
    goto start3;
  }
   
 
  cout << "Please, Enter the width: \n";
  start4:;
  cin >> w;
   if(x+w<x){
    cout<<"invalid input, width must be positive\n";
    goto start4;
  }
 int v=x+w,vv=y+l;
 if(x+w>255){
  v=255;
 }
 if(y+l>255){
  vv=255;
 }
  unsigned char temp[SIZE][SIZE][RGB];
  for (int i = x; i < v && i < SIZE; i++)
  {
    for (int j = y; j < vv && y < SIZE; j++)
    {
      temp[i][j][0] = image[i][j][0];
      temp[i][j][1] = image[i][j][1];
      temp[i][j][2] = image[i][j][2];
      arr[i][j] = 1;
    }
  }
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      if (!arr[i][j])
      {
        temp[i][j][0] = 255;
        temp[i][j][1] = 255;
        temp[i][j][2] = 255;
      }
    }
  }
  for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=temp[i][j][q];
     }
     }
  }};
void shuffle()
{

  vector<vector<vector<int>>> arr[4];
  int y = 0;
  for (int i = 0; i < 4; i++)
  {
    vector<vector<int>>vv;
    vv.resize(129,vector<int>(RGB));
    arr[i].resize(129, vv);
  }
  for (int i = 0; i <= 128; i++)
  {
    for (int j = 0; j <= 128; j++)
    {
      arr[y][i][j][0] = image[i][j][0];
      arr[y][i][j][1] = image[i][j][1];
      arr[y][i][j][2] = image[i][j][2];
    }
  }
  int v = 0;
  y = 1;
  for (int i = 0; i <= 128; i++)
  {
    int u = 0;
    for (int j = 129; j < 256; j++)
    {
      arr[y][i][u][0] = image[i][j][0];
      arr[y][i][u][1] = image[i][j][1];
      arr[y][i][u][2] = image[i][j][2];
      u++;
    }
  }
  y = 2;
  v = 0;
  for (int i = 129; i <= 255; i++)
  {
    for (int j = 0; j <= 128; j++)
    {
      arr[y][v][j][0] = image[i][j][0];
      arr[y][v][j][1] = image[i][j][1];
      arr[y][v][j][2] = image[i][j][2];
    }
    v++;
  }
  y = 3;
  v = 0;
  for (int i = 129; i <= 255; i++)
  {
    int u = 0;
    for (int j = 129; j <= 255; j++)
    {
      arr[y][v][u][0] = image[i][j][0];
      arr[y][v][u][1] = image[i][j][1];
      arr[y][v][u][2] = image[i][j][2];
      u++;
    }
    v++;
  }
  cout << "Please, Enter the sequence that you want the image to be shuffled \n";
  cout << " ----------------------------------------------------------------------\n"
       << "|           /|                  |                 _                  |\n"
       << "|            |                  |                / \\                 |\n"
       << "|            |                  |                  /                 |\n"
       << "|           |                 |                /_                |\n"
       << "----------------------------------------------------------------------\n"
       << "|            __                 |               |      |             |\n"
       << "|           /  \\                |               |______|             |\n"
       << "|           ___/                |                      |             |\n"
       << "|              \\                |                      |             |\n"
       << "|           ___/                |                      |             | \n"
       << "----------------------------------------------------------------------  \n";
  vector<int> vv(4);
  for (int i = 0; i < 4; i++)
  {
    cin >> vv[i];
  }
  // unsigned char temp[SIZE][SIZE];
  v = 0;
  int u = 0;
  for (int i = 0; i < 4; i++)
  {
    v = (i <= 1) ? 0 : 128;
    for (int ii = 0; ii < 129; ii++)
    {
      u = 0;
      for (int jj = 0; jj < 129; jj++)
      {
        image[v][u][0] = arr[vv[i] - 1][ii][jj][0];
        image[v][u][1] = arr[vv[i] - 1][ii][jj][1];
        image[v][u][2] = arr[vv[i] - 1][ii][jj][2];
        u++;
      }
      v++;
    }
    i++;
    v = (i <= 1) ? 0 : 128;
    for (int ii = 0; ii < 129; ii++)
    {
      u = 129;
      for (int jj = 0; jj < 129; jj++)
      {
        image[v][u][0] = arr[vv[i] - 1][ii][jj][0];
        image[v][u][1] = arr[vv[i] - 1][ii][jj][1];
        image[v][u][2] = arr[vv[i] - 1][ii][jj][2];
        u++;
      }
      v++;
    }
  }
  //saveImage();
}
void skewV()
{
  start:;
  int degree;
  cout << "Please, Enter the degree of your skew between -45 to 45\n";
  cin >> degree;
  bool ck = true;
   if(abs(degree)>45){
    cout<<"Ivalid input\n";
    goto start;
  }
  if (degree < 0)
  {
    ck = false;
    degree = abs(degree);
  }

  //  int h=((degree*(22/7))/180)<<'\n';
  double y = tanf(((degree * (22 / 7.0)) / 180.0));
  int p = y * 256;
   // cout<<p<<endl;
  // cout<<y<<endl;
  unsigned char temp[SIZE][SIZE][RGB];
  int m = (256 / (double)(256 - (256 * y)));
  double g=(256 / (double)(256 - (256 * y)));
  double rem=g-m,rem2=g-m;
  // cout<<m<<endl;
  // cout<<m<<endl;
  int u = 256, w = 1;
  for (int i = 0; i < 256; i++)
  {
    int h, g;
    if (ck)
    {
      h = u * y, g = w * y;
    }
    else
    {
      h = w * y, g = u * y;
    }
    for (int j = 0; j < h; j++)
    {
      temp[i][j][0] = 255,temp[i][j][1] = 255,temp[i][j][2] = 255;
    }
    for (int j = 255; j >= 255 - g; j--)
    {
      temp[i][j][0] = 255,temp[i][j][1] = 255,temp[i][j][2] = 255;
    }
    int r = 0;
    int yy = m;
    for (int j = h; j < 255 - g; j++)
    {
      int sum = 0,sum1=0,sum2=0;
      int v=0,vv=0;
      for (int k = r; k < yy; k++)
      {
        v++;
        sum += image[i][k][0];
        sum1 += image[i][k][1];
        sum2 += image[i][k][2];
      }
      if(rem>=1){
  rem--;
  sum+=image[i][r+v][0],sum1+=image[i][r+v][1],sum2+=image[i][r+v][2];
  vv=1;

      }
      rem+=rem2;
      temp[i][j][0] = sum /( m+vv),temp[i][j][1] = sum1 /( m+vv),temp[i][j][2] = sum2 /( m+vv);
      r += (m+vv);
      yy += (m+vv);
    }
    u--, w++;
  }
  for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=temp[i][j][q];
     }
     }
  }
}
void skewH()
{
  start:;
  int degree;

  cout << "Please, Enter the degree of your skew between -45 to 45 inclusive\n";
  cin >> degree;
  if(abs(degree)>45){
    cout<<"Ivalid input\n";
    goto start;
  }
  bool ck = true;
  if (degree < 0)
  {
    ck = false;
    degree = abs(degree);
  }

  //  int h=((degree*(22/7))/180)<<'\n';
  double y = tanf(((degree * (22 / 7.0)) / 180.0));
  int p = y * 256; // cout<<p<<endl;
  // cout<<y<<endl;
  unsigned char temp[SIZE][SIZE][RGB];
  int m = 256 / (256 - (256 * y));
  double g=256 /double (256 - (256 * y));
  // cout<<m<<endl;
double rem=g-m,rem2=g-m;
  int u = 256, w = 1;
  for (int i = 0; i < 256; i++)
  {
    int h, g;
    if(ck)
    {
      h = u * y, g = w * y;
    }
    else
    {
      h = w * y, g = u * y;
    }
   // cout<<h<<" "<<g<<endl;
    for (int j = 0; j < h; j++)
    {
      temp[j][i][0] = 255;temp[j][i][1] = 255;temp[j][i][2] = 255;
    }
    for (int j = 255; j >= 255 - g; j--)
    {
      temp[j][i][0] = 255;temp[j][i][1] = 255;temp[j][i][2] = 255;
    }
    int r = 0;
    int yy = m;
    for (int j = h; j < 255 - g; j++)
    {
      int sum1 = 0,sum2 = 0,sum3 = 0;
      int v=0;
      int vv=0;
      for (int k = r; k < yy; k++)
      {
        v++;
        sum1 += image[k][i][0];
        sum2+=image[k][i][1];
        sum3+=image[k][i][2];
      }
if(rem>=1){
  rem--;
 sum1 += image[r+v][i][0];
        sum2+=image[r+v][i][1];
        sum3+=image[r+v][i][2];
      vv=1;
}

      temp[j][i][0] = sum1 / (m+vv);
      temp[j][i][1] = sum2 / (m+vv);
      temp[j][i][2] = sum3 / (m+vv);
      
      r += m+vv;
      rem+=rem2;
      
      yy += m+vv;
    }
    u--, w++;
  }
  char imageFileName[100];

  for (int i =0;i<256;i++){
    for (int j =0;j<256;j++)
     {
      for(int q=0;q<256;q++){
       image[i][j][q]=temp[i][j][q];
     }
     }
  }
}
int main()
{
  // loadImage();
  // doSomethingForImage();
  // saveImage();
  cout << "Hello dear user, Welcome to our amazing program" << endl;
    cout << "Note, this program dealing only with colored images\n";
  cout << "**********************************************************************" << endl;
  cout << endl;
  cout << "Kindly Select a number that maps to the option you want from the below options or Type \'0\' to exit: " << endl
       << endl;
  string choice;
  bool ck = true;
  int nnn=0;
  while (true)

  {
    // cout<<ck<<endl;
    if (!ck)
    {
      cout << "your input is out of boundary or invalid\n"
           << "Please, type a valid number \'between 0 to 15 inclusive\'" << endl;
    }

    cout <<"0) for exit\n" "1) Black & White Filter\n"
            "2) Invert Filter\n"
            "3) Merge Filter \n"
            "4) Flip Image\n"
            "5) Rotate Image \n"
            "6) Darken or Lighten\n"
            "7) Detect Image Edges \n"
            "8) Enlarge Image\n"
            "9) Shrink Image\n"
            "10) Mirror 1/2 Image\n"
            "11) Shuffle Image\n"
            "12) Blur Image\n"
            "13) Crop Image\n"
            "14) Skew Image Right  \n"
            "15) Skew Image Up  \n"
     "16) Save the image to a file " << endl;
    cout << "-------------------------------------------------------" << endl;
    cin >> choice;
    bool flag = true;
    ;
    int u = 0;
    // cout<<choice.size()<<endl;
    for (int i = 0; i < choice.size(); i++)
    {
      if (isalpha(choice[i]))
      {
        flag = false;
        break;
      }
      else
      {
        u *= 10;
        u += (choice[i] - '0');
        // cout<<u<<endl;
      }
    }
    if (u == 0 && flag)
      break;

    if (flag)
    {
      flag = (u > 0 && u < 17) ? 1 : 0;
    }

    if (!flag)
    {
      ck = false;
      continue;
    }

    ck = true;
    // cout<<u<<endl;
    Show_Menu(u,nnn);
    nnn=1;
    cout << "-----------------------------------------------------------" << endl;
  }
  cout << "We hope that our program was useful for you, you can share us your impression of the program if you want or type \'NO\' to exit: " << endl;

  string s;
  cin >> s;
  cout << "Thanks for your opinion. " << endl;
  return 0;
}
void loadImage()
{
  char imageFileName[100];

  // Get gray scale image file name
  cout << "Enter the source image file name: ";
  cin >> imageFileName;

  // Add to it .bmp extension and load image
  strcat(imageFileName, ".bmp");
  readRGBBMP(imageFileName, image);
}
void saveImage()
{
  char imageFileName[100];

  // Get gray scale image target file name
  cout << "Enter the target image file name: ";
  cin >> imageFileName;

  // Add to it .bmp extension and load image
  strcat(imageFileName, ".bmp");
  writeRGBBMP(imageFileName, image);
}
