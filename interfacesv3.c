#include <ncurses.h>
#include <locale.h>

/*
ЗЗадание 4.
	Попрактикуйтесь в выводе символов в разных местах экрана. Попробуйте стирать
	или заменять уже напечатанные символы.
	*/
/* прототипы функций */
int nc_start (void);
void nc_end (void);


/* главная функция */
int main (void)
{
	setlocale(LC_ALL, "");
	int ErrorCode;
	int i,j;

	int hello[12] = { 'H','e','l','l','o', ' ', 'w', 'o', 'r', 'l', 'd', '!' };
	char * symbol[] = { "П","р","и","в","е","т", " ", "м", "и", "р", " ", "!" };

	ErrorCode = nc_start();				// инициируем сессию ncurses
	if (ErrorCode == 0)					// есл проверка инициирования успешна
	{
		for(i = 0; i < 12; i++)
		{
			move(5+i, 30+i);
			printw("%c", hello[i]);
			refresh();
		}
		for(j = 11; j >= 0; j--)
		{
			move(5+j, 53-j);
			printw("%s", symbol[j]);
			refresh();
		}

		nc_end();							// завершаем сессию ncurses
	}
	return ErrorCode;						// передаем код завершения
}



/* начало */
int nc_start (void)
{
	int code = 0;
	if(initscr() < 0) { code = -1; }	// инициируем сессию ncurses с проверкой
	return code;
}



/* конец */
void nc_end (void)
{
	move(23,0);								// перемещаем курсор на последнюю строку
	printw("Press any key to continue...");
	refresh();								// обновляем экран
	getch();									// ждем нажатия любой кнопки
	clear();									// очищаем окно stdscr
	refresh();
	endwin();								// завершаем сессию ncurses
	return;
}
