compile: gcc -g src/main.c src/glad.c src/games/number_memory.c -Iinclude -Llib -lglfw3dll -lopengl32 -lgdi32 -o memorygame.exe
run: ./memorygame.exe

make next make window output, fix so it dosent generate a new number while in a level fix input




 