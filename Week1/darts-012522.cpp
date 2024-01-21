#include <iostream>

int main() {

    int loop,score,x,y;
    score=0;
    std::cin >> loop;
    for (int i =0;i<loop;i++){
        
        std::cin >> x >> y;
        if ((x*x + y*y)<= 4){
            score += 5;
        }else if ((x*x + y*y)<= 16){
            score +=4;
        }else if ((x*x + y*y)<= 36){
            score +=3;
        }else if ((x*x + y*y)<= 64){
            score +=2;
        }else if ((x*x + y*y)<= 100){
            score +=1;
        }
    }
    // std::cout << "Out of loop" << std::endl;
    std::cout << score << std::endl;

    return 0;
}
