using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessBoard
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.Write("Введите Размер поля: ");
            int size = Convert.ToInt32(Console.ReadLine());
            int x, y = 0;
            x = 0;
            y = 2;
            if (size <= 0) Console.WriteLine("Некорректный размер");


            void kvadrat(int X, int Y, ConsoleColor color)
            {
                for (int i = 0; i < 5; i++)
                {
                    Console.ForegroundColor = color;
                    Console.BackgroundColor = color;
                    Console.SetCursorPosition(X, Y + i);
                    for (int j = 0; j < 5; j++)
                    {
                        
                        Console.Write("* ");
                    }
                    Console.Write('\n');
                }
                Console.ResetColor();
            }
            

            void Chessboard(int X = 0, int Y = 0)
            {

                int temp = X;
                for (int i = 0; i < size; i++)
                {

                    for (int j = 0; j < size; j++)
                    {

                        if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                        {
                            kvadrat(X, Y, ConsoleColor.DarkRed);
                        }
                        else
                        {
                            kvadrat(X, Y, ConsoleColor.White);
                        }
                        X += 5 * 2;
                    }
                    X = temp;//возвращаем значение которое передали
                    Y += 5;
                    Console.Write('\n');
                }
            }


            Chessboard(0, 3);

        }
    }
}
