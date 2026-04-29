#include "number_memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GLFW/glfw3.h>

typedef enum{
    Show_number,
    Input,
    Result
} GameState;

static GameState state;
static int level = 1;
static long currentNumber = 0;
static double showStartTime = 0.0;

static char inputBuffer[32];
static int inputIndex = 0;


long generateNumber(int digits)
{
    long min = 1;
    for (int i = 1; i < digits; i++)
        min *= 10;

    long max = min * 10 - 1;

    return min + rand() % (max - min + 1);
}

//starter level
void number_memory_init(){
    srand(time(NULL));

    level = 1;
    currentNumber = generateNumber(level);
    showStartTime = glfwGetTime();
    state = Show_number;

}

void update_memory_number(float time){
    if(state == Show_number){
        if(time - showStartTime > 2.0){
            state == Input;
        }
    }
}

void render_memory_number(){
    if(state == Show_number){
        printf("level | Memorize: %ld  ",level, currentNumber);
    }
    else if(state == Input){
        printf("input number",inputBuffer);
    }
    else if(state == Result){
        printf("\n");
    }
    
}

void input_memory_number(int key){
    if(state != Input) return;

    // 0 to 9

    if(key >= GLFW_KEY_0 && GLFW_KEY_9){
        if(inputIndex < 30){
            inputBuffer[inputIndex++] = '0' + (key - GLFW_KEY_0);
            inputBuffer[inputIndex] = '\0';
        }
    }

    //backspace
    if(key == GLFW_KEY_BACKSPACE && inputIndex > 0){
        inputIndex--;
        inputBuffer[inputIndex] = '\0';
    }

    //enter go to next level if correct
    if(key == GLFW_KEY_ENTER && inputIndex > 0){
        long guess;
        if(guess == currentNumber){
            printf("\ncorrect\n");
            level++;
            inputIndex == 0;
            inputBuffer[0] = '\0';

            currentNumber = generateNumber(level);
            showStartTime = glfwGetTime();
            state = Show_number;
        }
        else{
            printf("\nyou lost\n");
            state = Result;
            
        }
    }

}