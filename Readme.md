compile: gcc src/main.c src/glad.c -Iinclude -Llib -o memorygame.exe -lglfw3dll -lopengl32 -lgdi32
run: ./memorygame.exe


 -Iinclude -Llib -lglfw3dll -lopengl32 -lgdi32 -o


 gcc -g src/main.c src/glad.c -Iinclude -Llib -lglfw3dll -lopengl32 -lgdi32 -o memorygame.exe