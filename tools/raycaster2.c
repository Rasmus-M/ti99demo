/*
    Code shamelessly ripped from http://lodev.org/cgtutor/raycasting.html
*/

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdint.h>

#define MOD(x, m) (((x) % (m) + (m)) % (m))

uint8_t map[16][16] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    
};

#define WIDTH 128 * 4
#define HEIGHT 64 * 4
#define BSIZE 1024 * 1024
int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *surface = SDL_SetVideoMode(WIDTH, HEIGHT, 32, 0);
    uint32_t* pixels = (uint32_t*) (surface->pixels);
    SDL_Event event;
    int done = 0, color;
    double posX = 1.5, posY = 1.5;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame
    int w = WIDTH, h = HEIGHT, key[4] = {0, 0, 0, 0};
    int j = 0;
    double *buffer = (double *)calloc(BSIZE, sizeof(double));
    double *p = buffer;
    
    while (!done && j < BSIZE)
    {
        for(int x = 0; x < w; x++)
        {
            //calculate ray position and direction
            double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
            double rayPosX = posX;
            double rayPosY = posY;
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;        
            
            //which box of the map we're in
            int mapX = (int)rayPosX;
            int mapY = (int)rayPosY;

            //length of ray from current position to next x or y-side
            double sideDistX;
            double sideDistY;

            //length of ray from one x or y-side to next x or y-side
            double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
            double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
            double perpWallDist;

            //what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;

            int hit = 0; //was there a wall hit?
            int side; //was a NS or a EW wall hit?            
            

            //calculate step and initial sideDist
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (rayPosX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (rayPosY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
            }            
            //perform DDA
            while (hit == 0)
            {
                //jump to next map square, OR in x-direction, OR in y-direction
                if (sideDistX < sideDistY)
                {
                  sideDistX += deltaDistX;
                  mapX += stepX;
                  side = 0;
                }
                else
                {
                  sideDistY += deltaDistY;
                  mapY += stepY;
                  side = 1;
                }
                //Check if ray has hit a wall
                if (map[mapX][mapY] > 0) hit = 1;
            } 
            
            //Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
            if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
            else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

            //Calculate height of line to draw on screen
            int lineHeight = (int)(h / (perpWallDist));
            double lhd = h / (perpWallDist);
            if (lineHeight > HEIGHT) lineHeight = HEIGHT;
            if (lhd > HEIGHT) lhd = HEIGHT;
            
            if ((x & 7) == 0)
            {
                *(p++) = lhd / 8.0;
                *(p++) = (double)side;
                j += 2;
            }

            //calculate lowest and highest pixel to fill in current stripe
            int drawStart = -lineHeight / 2 + h / 2;
            if(drawStart < 0)drawStart = 0;
            int drawEnd = lineHeight / 2 + h / 2;
            if(drawEnd >= h)drawEnd = h - 1;
            
            if (side == 1) color = 0x00FF0000;
            else color = 0x007F0000;
            for (int y = 0; y < HEIGHT; y++) pixels[x + y * WIDTH] = 0;
            for (int y = drawStart; y < drawEnd; y++)
            {
                if (y >= 0 && y < HEIGHT) pixels[x + y * WIDTH] = color;
            }
        }
        //timing for input and FPS counter
        oldTime = time;
        time = SDL_GetTicks();
        double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds

        //speed modifiers
        double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
        double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

        SDL_Flip(surface);
        
        // handle events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                done = 1;
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = 1;
                switch (event.key.keysym.sym)
                {
                    case SDLK_DOWN:  key[0] = 1; break;
                    case SDLK_UP:    key[1] = 1; break;
                    case SDLK_LEFT:  key[2] = 1; break;
                    case SDLK_RIGHT: key[3] = 1; break;                    
                    default: break;
                }
            }

            if (event.type == SDL_KEYUP)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_DOWN:  key[0] = 0; break;
                    case SDLK_UP:    key[1] = 0; break;
                    case SDLK_LEFT:  key[2] = 0; break;
                    case SDLK_RIGHT: key[3] = 0; break;                    
                    default: break;
                }                
            }
        }
        
        if (key[0])
        {
            if(!map[(int)(posX - dirX * moveSpeed)][(int)(posY)]) posX -= dirX * moveSpeed;
            if(!map[(int)(posX)][(int)(posY - dirY * moveSpeed)]) posY -= dirY * moveSpeed;
        }
        if (key[1])
        {
            if (!map[(int)(posX + dirX * moveSpeed)][(int)(posY)]) posX += dirX * moveSpeed;
            if (!map[(int)(posX)][(int)(posY + dirY * moveSpeed)]) posY += dirY * moveSpeed;
        }
        if (key[3])
        {
                //both camera direction and camera plane must be rotated
                double oldDirX = dirX;
                dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
                dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
                double oldPlaneX = planeX;
                planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
                planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);            
        }
        if (key[2])
        {
                //both camera direction and camera plane must be rotated
                double oldDirX = dirX;
                dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
                dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
                double oldPlaneX = planeX;
                planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
                planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);                                    
        }
    }
    
    p = buffer;
    FILE *f = fopen("casterdata.a99", "wb");
    int frame = 0;
    int bytes_written = 0;
    while (p[0] && bytes_written < 8190 - 256)
    {
        int z = 0;
        double delta = 0;
        int curside = 0;
        int working = 0;
        int width = 0;
        int iheight = 0;
        fprintf(f, "* Frame %d\n", frame);
        for (int i = 0; i < 128; i += 2)
        {
            if (!working)
            {
                if (i < 126 && p[i + 1] == p[i + 3])
                {
                    delta = p[i+2] - p[i];
                    curside = p[i+1];
                    width = 2;
                    z += 2;
                    working = 1;
                    iheight = (int)p[i];
                }
                else
                {
                    fprintf(f, "        DATA >0000\n");
                    fprintf(f, "        BYTE %d, %d\n", (unsigned char)p[i], (unsigned char)(2+p[i+1]));
                    z++;
                    bytes_written += 4;
                }
            }
            else
            {

                if (i < 126 && fabs((p[i + 2] - p[i]) - delta) < 0.001 && curside == (int)p[i + 1])
                {
                    width++;
                    z++;
                }
                else
                {
                    uint16_t d = delta * 256;
                    fprintf(f, "        DATA >%04X\n", d);
                    fprintf(f, "        BYTE %d, %d\n", iheight, width << 1 | curside);
                    working = 0;
                    bytes_written += 4;
                }
            }
        }
        
        if (z != 64)
        {
            fprintf(f, "* Bad frame! (%d)\n", z);
        }
        p += 512;
        frame++;
    }
    fclose(f);
    free(buffer);
    SDL_Quit();
    return 0;
}