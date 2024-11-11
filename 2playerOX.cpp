//tictactoe??
#include<iostream>
#include<vector>
 std::vector <std::vector<char>> squares{{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 
 char turn = 'O';



void board(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<squares[i][j]<<" ";
        }
        std::cout<<"\n\n";
    }

}
void iscorner(){
    
}

bool checkmove(int place){
    int x=(place-1)/3;
    int y=(place-1)%3;
    return squares[x][y]!='X'&&squares[x][y]!='O';
    
    
}
void move_verified(int place){
    int x=(place-1)/3;
    int y=(place-1)%3;
    squares[x][y]=turn;
    if(turn=='O'){
        turn='X';
    }
    else{
        turn='O';
    }

}
void update_board(){
    char dupli[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            dupli[i][j]=squares[i][j];            
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(dupli[i][j]!='X'&&dupli[i][j]!='O'){
                dupli[i][j]='-';
            }            
        }
    }
    std::cout<<"\n\nUpdate :\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<dupli[i][j]<<" ";            
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n\n";
    
}

bool isitover(){
    for(int i=0;i<3;i++){
        
            if(squares[i][0]==squares[i][1]&&squares[i][1]==squares[i][2]){
            return true;
            break;
            }

            else if(squares[0][i]==squares[1][i]&&squares[1][i]==squares[2][i]){
            return true;
            break;
            }

            else if((squares[0][0]==squares[1][1]&&squares[1][1]==squares[2][2])||
            (squares[0][2]==squares[1][1]&&squares[1][1]==squares[2][0])){
            return true;
            break;
            
            }     

    }
    return false;
}

bool isitdraw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(squares[i][j]!='O'&&squares[i][j]!='X')
            return false;
        }
    }
    return true;

}


int main(){
    std::cout<<"The squares :\n\n";
    board();
    int place;
    for(int i=0;i<9;i++){
    std::cout<<"Player : "<<turn<<std::endl;
    std::cout<<"Enter the square (1-9) : ";
    std::cin>>place;
    if(checkmove(place)){
        
        move_verified(place);
        update_board();
        if (isitover()==true){
            std::cout<<turn<<" lost the game!";
            break;
        }
        

        if(isitdraw()==true){
            std::cout<<"Draw.";
            break;
        }

    } 
    

    else{
        std::cout<<"Invalid place, You lost by disqualification.";
        break;
    } 
}
std::cout<<"\n\nThe END";
}