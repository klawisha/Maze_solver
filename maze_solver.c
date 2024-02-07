#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void iterative_search(char** maze, int start_x, int start_y, int size, char** directions, char* iter_dirs, int dir_cnt)
{
	char dirx[2];
	char diry[2];
	
	for(int i = 0; i < dir_cnt; i++)				// clear array
		memset(directions, '\0', sizeof(char)*50 );
	dir_cnt = 0;
	
	for(int i = 0; i < size; ++i)
	{
		directions[dir_cnt] = (char*)malloc(50);
		
		switch(iter_dirs[i])
		{
			case 'S':		// South
			
			maze[start_x][start_y] = '.';

			if(maze[start_x+1][start_y+1] == 'C')	// if found
			{
				printf("\nJerry found the cheese.\n");
				strcpy(directions[dir_cnt],"Jerry found the cheese.");
				return;
			}

			if(maze[start_x+1][start_y+1] == '|')	// if wall
			{
				continue;
			}
			else	// move
			{
			itoa(start_x+1, dirx, 10);
			itoa(start_y, diry, 10);
			strcpy(directions[dir_cnt],"Jerry moved South (");
			strcat(directions[dir_cnt], dirx);
			strcat(directions[dir_cnt], ", ");
			strcat(directions[dir_cnt], diry);
			strcat(directions[dir_cnt], ")");
			dir_cnt++;
			
			start_x += 1;
			start_y += 1;				
			}
			break;
			
			case 'N':
			
			maze[start_x][start_y] = '.';
			
			if(maze[start_x-1][start_y-1] == 'C')
			{
				printf("\nJerry found the cheese.\n");
				strcpy(directions[dir_cnt],"Jerry found the cheese.");
				return;
			}

			if(maze[start_x-1][start_y-1] == '|')
			{
				continue;
			}
			else
			{
			itoa(start_x-1, dirx, 10);
			itoa(start_y, diry, 10);
			strcpy(directions[dir_cnt],"Jerry moved North (");
			strcat(directions[dir_cnt], dirx);
			strcat(directions[dir_cnt], ", ");
			strcat(directions[dir_cnt], diry);
			strcat(directions[dir_cnt], ")");
			dir_cnt++;
			
			if(maze[start_x-1][start_y-1] == 'C')
			{
				printf("\nJerry found the cheese.");
				strcpy(directions[dir_cnt],"Jerry found the cheese.");
				return;
			}			
			start_x -= 1;
			start_y -= 1;
			}
			break;
			
			case 'W':
			
			if(maze[start_x][start_y-1] == 'C')
			{
				printf("\nJerry found the cheese.");
				strcpy(directions[dir_cnt],"Jerry found the cheese.");
				return;
			}

			maze[start_x][start_y] = '.';

			if(maze[start_x][start_y-1] == '|')
			{
				continue;
			}
			else
			{
			itoa(start_x, dirx, 10);
			itoa(start_y-1, diry, 10);
			strcpy(directions[dir_cnt],"Jerry moved West (");
			strcat(directions[dir_cnt], dirx);
			strcat(directions[dir_cnt], ", ");
			strcat(directions[dir_cnt], diry);
			strcat(directions[dir_cnt], ")");
			dir_cnt++;
			
			start_y -= 1;
			}
			break;
			
			case 'E':
			maze[start_x][start_y] = '.';
    		
			if(maze[start_x][start_y+1] == 'C')
			{
				printf("\nJerry found the cheese.");
				strcpy(directions[dir_cnt],"Jerry found the cheese.");
				return;
			}

			if(maze[start_x][start_y+1] == '|')
			{
				continue;
			}
			else
			{
			itoa(start_x, dirx, 10);
			itoa(start_y+1, diry, 10);
			strcpy(directions[dir_cnt],"Jerry moved East (");
			strcat(directions[dir_cnt], dirx);
			strcat(directions[dir_cnt], ", ");
			strcat(directions[dir_cnt], diry);
			strcat(directions[dir_cnt], ")");
			dir_cnt++;
			
			start_y += 1;
			}
			break;

		}
	}
	
}

int recursive_search(char** maze, int start_x, int start_y, char** directions, int dir_cnt)
{
    char test = maze[start_x][start_y];

	char dirx[5];
	char diry[5];
		
	directions[dir_cnt] = (char*)malloc(50);
	
                 
    //If cheese
    if (test == 'C'){
        printf("\nJerry found the cheese.\n");
	 strcpy(directions[dir_cnt],"Jerry found the cheese.");
        return 0;
    }
     
    //Index error
    if (start_x < 0 || start_y < 0 || start_x >= ROWS || 
         start_y >= COLS){
         printf("Error: bounds error.\n");
         return -1;   
     }//End out of bounds if
      
      //If function can go down
      if (maze[start_x+1][start_y+1] == ' ' || maze[start_x+1][start_y+1] == 'C'){
        maze[start_x][start_y] = '.';
		itoa(start_x+1, dirx, 10);
		itoa(start_y, diry, 10);
        strcpy(directions[dir_cnt],"Jerry moved South (");
        strcat(directions[dir_cnt], dirx);
		strcat(directions[dir_cnt], ", ");
		strcat(directions[dir_cnt], diry);
		strcat(directions[dir_cnt], ")");
		dir_cnt++;
		 
        return recursive_search(maze, start_x+1, start_y+1);
      }
      
      //If function can go right
      if (maze[start_x][start_y+2] == ' ' || maze[start_x][start_y+2] == 'C'){
         maze[start_x][start_y] = '.';
		itoa(start_x, dirx, 10);
		itoa(start_y+1, diry, 10);
		strcpy(directions[dir_cnt],"Jerry moved East (");
        strcat(directions[dir_cnt], dirx);
		strcat(directions[dir_cnt], ", ");
		strcat(directions[dir_cnt], diry);
		strcat(directions[dir_cnt], ")");
		dir_cnt++;

        return recursive_search(maze, start_x, start_y+2);
      }
      
      //If function can go left
      if (maze[start_x][start_y-1] == ' ' || maze[start_x][start_y-1] == 'C'){
         maze[start_x][start_y] = '.';
		itoa(start_x, dirx, 10);
		itoa(start_y-1, diry, 10);
		strcpy(directions[dir_cnt],"Jerry moved West (");
        strcat(directions[dir_cnt], dirx);
		strcat(directions[dir_cnt], ", ");
		strcat(directions[dir_cnt], diry);
		strcat(directions[dir_cnt], ")");
		dir_cnt++;

        return recursive_search(maze, start_x, start_y-1);
      } 
      
      //If function can go up
      if (maze[start_x-1][start_y-1] == ' ' || maze[start_x-1][start_y-1] == 'C'){
         maze[start_x][start_y] = '.';
        itoa(start_x-1, dirx, 10);
		itoa(start_y, diry, 10);
		strcpy(directions[dir_cnt],"Jerry moved North (");
        strcat(directions[dir_cnt], dirx);
		strcat(directions[dir_cnt], ", ");
		strcat(directions[dir_cnt], diry);
		strcat(directions[dir_cnt], ")");
		dir_cnt++;

        return recursive_search(maze, start_x-1, start_y-1);
      }    
      
      //set back way down
      if (maze[start_x+1][start_y] == '.'){
            maze[start_x][start_y] = '*';
            return recursive_search(maze, start_x+1, start_y);
      }
      
      //back way up
      if (maze[start_x-1][start_y] == '.'){
            maze[start_x][start_y] = '^';
            return recursive_search(maze, start_x-1, start_y);
      } 
      
      //back way left
      if (maze[start_x][start_y-1] == '.'){
            maze[start_x][start_y] = '<';
            return recursive_search(maze, start_x, start_y-1);
      } 
      
      //back way right
      if (maze[start_x][start_y+1] == '.'){
            maze[start_x][start_y] = '>';
            return recursive_search(maze, start_x, start_y+1);
      } else 
         return -1;//If all else fails, maze is unsolvable   
	
	return 1;
}

void formatMaze(char** maze)				// format func to not draw logic with '*'
{
	for(int i = 0; i < ROWS; ++i)
		{
			for(int j = 0; j < COLS; ++j)
			{
				if(maze[i][j] == '>' || maze[i][j] == '<')
					maze[i][j] = '.';
			}
		}
}

int main(int argc, char** argv)
{
		int ROWS = 11;
		int COLS = 36;
		int dir_cnt = 0;
		char iter_dirs[70];
		char* directions[50];
		
		FILE* f_input;
		FILE* s_input;
		FILE* iter_out;
		FILE* rec_out;
		
		if(argc < 3)
		{
			printf("Error: two input files were not provided as command line arguments.\n");
			return EXIT_FAILURE;
		}
		
		char** maze = (char**)malloc(ROWS * sizeof(char*));	// set to 0
		for (int i = 0; i < ROWS; i++)
			maze[i] = (char*)malloc(COLS * sizeof(char));
		
		
		if ((f_input = fopen(argv[1], "r")))	// read maze
		{
			for(int i = 0; i < ROWS; ++i)
			{
				for(int j = 0; j < COLS; ++j)
				{
					maze[i][j] = (char)fgetc(f_input);
				}
			}
			fclose(f_input);
		}
		else
		{
			printf("Error: the %s file could not be opened.\n", argv[1]);
			return EXIT_FAILURE;
		}
	
		int cnt = 0;	
		char c;
		if ((s_input = fopen(argv[2], "r")))	// read directions
		{
			while(1)
			{
				char c = getc(s_input);
				if(c == EOF)
					break;
				iter_dirs[cnt] = c;			
				cnt++;
			}		
			fclose(f_input);
		}
		else
		{
			printf("Error – the %s file could not be opened.\n", argv[2]);
			return EXIT_FAILURE;
		}
	
		for(int i = 0; i < ROWS; ++i)	// print maze
		{
				for(int j = 0; j < COLS; ++j)
				{
					printf("%c", maze[i][j]);
				}
		}
		
		printf("\n\n============================================\nIterative solver\n============================================\n\n");
		
		iterative_search(maze, 2, 20, cnt, directions, iter_dirs, dir_cnt);
		
		for(int i = 0; i < ROWS; ++i)	// solved with iter
		{
			for(int j = 0; j < COLS; ++j)
			{
				printf("%c", maze[i][j]);
			}
		}
	
		iter_out = fopen("iterarive_labryint.out","w+");
   
		if (iter_out)
		{
			for(int i = 0; i < ROWS; ++i)	// print solved maze
			{
				for(int j = 0; j < COLS; ++j)
				{ 
					fputc(maze[i][j], iter_out);
				}
			}
			
			for(int i = 0; i < dir_cnt; ++i)		// print move directions
			{
				fputc('\n', iter_out);
				fputs(directions[i], iter_out);
			}
		}
		else
		{
			printf("Failed to open the file\n");
			return EXIT_FAILURE;
		}
		close(iter_out); // close
	
		if ((f_input = fopen(argv[1], "r")))		// read again
			{
				for(int i = 0; i < ROWS; ++i)
				{
					for(int j = 0; j < COLS; ++j)
					{
						maze[i][j] = (char)fgetc(f_input);
					}
				}
				fclose(f_input);
			}
			else
			{
				printf("Error – the %s file could not be opened.\n", argv[1]);
				return EXIT_FAILURE;
			}

		for(int i = 0; i < dir_cnt; i++)				// set to 0
			memset(directions, '\0', sizeof(char)*50 );
		dir_cnt = 0;	
		
		printf("\n\n============================================\nRecursive solver\n============================================\n\n");

		int result = recursive_search(maze, 2, 20, directions, dir_cnt);
		
		if(result == -1)
		{
			printf("Error: can't solve the maze recursive.\n");
			return EXIT_FAILURE;
		}
		
		formatMaze(maze);
		for(int i = 0; i < ROWS; ++i)
		{
			for(int j = 0; j < COLS; ++j)
			{
				printf("%c", maze[i][j]);
			}
		}

		rec_out = fopen("recursive_labryinth.out","w+");
		
		if ( rec_out )
		{
			for(int i = 0; i < ROWS; ++i)
			{
				for(int j = 0; j < COLS; ++j)
				{ 
					fputc(maze[i][j], rec_out);
				}
			}
			
			for(int i = 0; i < dir_cnt; ++i)
			{
				fputc('\n', rec_out);
				fputs(directions[i], rec_out);
			}
			}
		else
			{
				printf("Failed to open the file\n");
				return EXIT_FAILURE;
			}
		
		fclose(rec_out);
		
	return EXIT_SUCCESS;
}