#include <iostream>

using namespace std;

int main(){
   char** display;
   display = new char*[25];
   for(int r = 0;r<25;r++){
        display[r]= new char[79];
     for(int c = 0;c<79;c++){
        display[r][c] = ' ';
     }
   }//initialize all the position to space
   for(int r = 0;r<25;r++){
        display[r][0] = '|';
        display[r][78] = '|';
   }  
   for(int i = 1;i<=77;i++){
        display[0][i] = '-';
    	display[24][i] = '-';
   } 
   for(int i =2;i<=7;i++){
	display[i][2] = '|';
    	display[i][29] ='|';
  }
   for(int r = 2;r<=7;r++){
      for(int c = 3;c<=28;c++){
         if(r == 2||r==7){
           display[r][c] = '-';
         }else{
           display[r][c] = '.';
         }   
      }
  }
  //chamber 1
   for(int i =14;i<=22;i++){
        display[i][3] = '|';
    	display[i][25] = '|';
   }
   for(int r = 14;r<=22;r++){
       for(int c = 4;c<=24;c++){
          if(r == 14 || r == 22){
             display[r][c]='-';
          }else{
             display[r][c]='.';
          }
       }
   } 
  //chamber 2
   for(int r = 9;r<=13;r++){
        display[r][37] = '|';
        display[r][50] = '|';
   }
   for(int r = 9;r<=13;r++){
       for(int c = 38;c<=49;c++){
         if(r == 9 || r==13){
            display[r][c] ='-';
         }else{
            display[r][c] ='.';
         }
       }
   }
  //chamber 3
   for(int r = 18;r<=22;r++){
         display[r][36] ='|';
         display[r][76] = '|';
   }
   for(int r = 15;r<=18;r++){
         display[r][64] = '|';
         display[r][76] = '|';
     for(int c = 65;c<=75;c++){
        if(r==15){
          display[r][c] ='-';
        }else{
          display[r][c] = '.';
        }
     }  
   }
   for(int c = 37;c<=63;c++){
        display[18][c]='-';
   }
   for(int r=19;r<=22;r++){
       for(int c=37;c<=75;c++){
          if(r == 22){
            display[r][c]='-';
          }else{
            display[r][c]='.';
          }
       }
   }
   //chamber 4
   for(int r = 2;r<=13;r++){
    if(r==2||r==3){
      for(int c = 39;c<=61;c++){
       if(r==2){
       display[r][c] = '-';
       }else{
       display[r][c] = '.';
       }
      }
    }
    else if(r==4){
      for(int c = 39;c<=62;c++){
      display[r][c] = '.';
      }
      for(int c = 63;c<=69;c++){
      display[r][c] = '-';
      }
    }
    else if(r == 5||r == 6){
      for(int c = 39;c<=72;c++){
      display[r][c] = '.';
      }
    }
    else if(r==7){
      for(int c = 39;c<=59;c++){
      display[r][c]= '-';
      }
      for(int c = 61;c<=75;c++){
      display[r][c] = '.';
      }
    }
    else if(r == 13){
       for(int c = 61;c<=75;c++){
       display[r][c] = '-';
       }
    }
    else{
       for(int c = 61;c<=75;c++){
       display[r][c] = '.';
       }
    }
   }
   display[5][71] = '-';
   display[5][72] = '-';
   display[6][74] = '-';
   display[6][75] = '-';
   for(int r = 2;r<=4;r++){
   display[r][38] = '|';
   display[r][62] = '|';
   }
   display[4][70] = '|';
   display[5][70] = '|';
   display[5][73] = '|';
   display[6][73] = '|';
   display[6][76] = '|';
   for(int r = 5;r<=7;r++){
   display[r][38] = '|';
   }
   for(int r = 7;r<=13;r++){
   display[r][60] = '|';
   display[r][76] = '|';
   }
//chamber 5
   
   display[4][29] = '+';
   display[4][38] = '+';
   display[9][43] = '+';
   display[13][43] = '+';
   display[11][60] = '+';
   display[7][13] = '+';
   display[14][13] = '+';
   display[20][25] = '+';
   display[20][36] = '+';
   display[18][43] = '+';
   display[15][69] = '+';
   display[13][69] = '+';
   display[7][43] = '+';
//initialize doors

   for(int r = 8;r<=13;r++){
   display[r][13] = '#';
   }
   for(int r = 5;r<=7;r++){
   display[r][33] = '#';
   }
   for(int r = 8;r<=20;r++){
   display[r][31] = '#';
   }
   for(int r = 11;r<=16;r++){
   display[r][54] = '#';
   }
   for(int r = 14;r<=17;r++){
   display[r][43] = '#';
   }
 
   display[14][69] = '#';

   for(int c = 14;c<=30;c++){
   display[11][c] = '#';
   }
   for(int c = 26;c<=35;c++){
   display[20][c] = '#';
   }
   for(int c = 32;c<=53;c++){
   display[16][c] = '#';
   }
   for(int c = 32;c<=43;c++){
   display[8][c] = '#';
   }
   for(int c = 30;c<=37;c++){
   display[4][c] = '#';
   }
   for(int c = 54;c<=59;c++){
   display[11][c] = '#';
   }
//initialize path

   for(int r = 0;r<25;r++){
     for(int c = 0;c<79;c++){
        cout << display[r][c];
     }
    cout << endl;
   }
}
