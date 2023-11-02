//#define CONSOLE_PARAMETERS
//#define STRING_OPERATIONS
//#define DATA_TYPES
//#define FIGURES
//#define LITERALS 
//#define CHESS
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Introduction
{
    class Program
    {

        static void Main(string[] args)
        {
            
#if CONSOLE_PARAMETERS
            Console.OutputEncoding = System.Text.Encoding.GetEncoding(28591);
            Console.WriteLine(Console.OutputEncoding.CodePage);
            Console.WriteLine(Console.OutputEncoding.EncodingName);
            for (int i = 0; i<256; i++)
                {
                if (i % 16 == 0) Console.WriteLine();
                Console.Write((char)i + " ");
                }
            Console.WriteLine();


            Console.Title = "Introduction to .NET";
            Console.Write("\tHello .NET\n"); //просто write пишет в одну строчку все
            Console.Write("Сам привет!\n");

            Console.SetCursorPosition(25, 15);
            Console.ForegroundColor = ConsoleColor.Green;
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.WriteLine("SetConsolCursorPosition"); //можно \n Написать или writeline (занимает всю строку)
            Console.ResetColor();
            Console.Beep();

            Console.CursorTop = 7;
            Console.CursorLeft = 25;
            Console.WriteLine("Вот и сказочке конец");
            Console.CursorSize = 100;
            Console.CursorVisible = true; 
#endif
#if STRING_OPERATIONS
            Console.Write("Введите ваше имя: ");
            string first_name = Console.ReadLine();

            Console.Write("Введите вашу фамилию: ");
            string last_name = Console.ReadLine();

            Console.Write("Введите Ваш возраст: ");
            int age = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Ваше имя: " + first_name + ", ваша фамилия: " + last_name + ", ваш возраст: " + age + " лет."); //конкатенация строк
            Console.WriteLine(string.Format("Ваше имя: {0}, Ваша фамилия: {1}, Ваш возраст: {2} лет", first_name, last_name, age)); // форматирование
            Console.WriteLine($"Ваше имя: {first_name}, Ваша фамилия: {last_name}, Ваш возраст: {age} лет."); // интерполяция строк

#endif
#if FIGURES
            int x = 0, y = 0;
            Console.WriteLine("Figure 0 : ");
            Console.WriteLine();
            int length = 5, width = 5;
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (j == 0 || j == width - 1) Console.Write("*");
                    else if (i == 0 || i == length - 1) Console.Write("*");
                    else Console.Write("*");
                }
                Console.WriteLine();
            }
            Console.WriteLine("Figure 1 : ");
            Console.WriteLine();
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (i >= j) Console.Write('*');
                }
                Console.Write("\n");
            }
            Console.WriteLine();
            Console.WriteLine("Figure 2 : ");
            Console.WriteLine();
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (i <= j) Console.Write('*');
                }
                Console.Write("\n");
            }
            Console.WriteLine();
            Console.WriteLine("Figure 3 : ");
            Console.WriteLine();
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (i >= j + 1) Console.Write(' ');
                    else Console.Write('*');
                }
                Console.Write("\n");
            }
            Console.WriteLine();
            Console.WriteLine("Figure 4 : ");
            Console.WriteLine();
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (j+i < length -1) Console.Write(' ');
                    else Console.Write('*');
                }
                Console.Write("\n");
            }
            x = 0;
            y = 41;
            Console.WriteLine();
            Console.WriteLine("Figure 5 : ");
            Console.WriteLine();
            for (int i = 0; i < length; i++)
            {
                Console.SetCursorPosition(x, y + i);
                for (int j = 0; j < width; j++)
                {
                    if (j + i != length - 1) Console.Write(' ');
                    else Console.Write('/');
                }
                Console.Write("\n");
            }
            x += width;
            for (int i = 0; i < length; i++)
            {
                Console.SetCursorPosition(x, y + i);
                for (int j = 0; j < width; j++)
                {
                    if (j != i) Console.Write(' ');
                    else Console.Write(@"\");
                }
                Console.Write("\n");
            }
            x = 0;
            y += length;
            for (int i = 0; i < length; i++)
            {
                Console.SetCursorPosition(x, y + i);
                for (int j = 0; j < width; j++)
                {
                    if (j != i) Console.Write(' ');
                    else Console.Write(@"\");
                }
                Console.Write("\n");
            }
            x += width;
            for (int i = 0; i < length; i++)
            {
                Console.SetCursorPosition(x, y + i);
                for (int j = 0; j < width; j++)
                {
                    if (j + i != length - 1) Console.Write(' ');
                    else Console.Write('/');
                }
                Console.Write("\n");
            }

            Console.WriteLine();

            Console.WriteLine("Figure 6 : ");
            Console.WriteLine();
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    Console.Write(i% 2 == 0 && j% 2 == 0 || i%2 !=0 && j % 2 != 0 ? '+' : '-');
                }
                Console.Write("\n");

            }
#endif
#if DATA_TYPES
            #region LOGICAL_TYPES
            //Console.WriteLine(true);
            //Console.WriteLine(false);
            //Console.WriteLine((bool).000000000000000000001);
            // Console.WriteLine(Convert.ToBoolean(.0000000000100));
            #endregion
            #region CHARACTER_TYPES
            //char - занимает 2 байта памяти и хранит один единственнй символ в коировке юникод
            //2^16 = 65 536
            #endregion
            #region NUMERIC_TYPE
            //Console.WriteLine(sizeof(int));
            //Console.WriteLine(int.MinValue+" ... "+int.MaxValue);
            Console.WriteLine($"Переменная типа  'int' занимает {sizeof(int)} Байт,\n" +
                $"и принимает значения в диапазоне: {int.MinValue} ... {int.MaxValue};");
            Console.WriteLine(delimiter);

            Console.WriteLine($"Переменная типа  'float' занимает {sizeof(float)} Байт,\n" +
               $"и принимает значения в диапазоне: {float.MinValue} ... {float.MaxValue};");
            Console.WriteLine(delimiter);

            Console.WriteLine($"Переменная типа  {typeof(float)} занимает {sizeof(float)} Байт,\n" +
              $"и принимает значения в диапазоне: {float.MinValue} ... {float.MaxValue};");
            //                              typeof(typename) typename-int,float и тд
            Console.WriteLine(delimiter);

            Console.WriteLine($"Переменная типа  {typeof(double)} занимает {sizeof(double)} Байт,\n" +
            $"и принимает значения в диапазоне: {double.MinValue} ... {double.MaxValue};");
            Console.WriteLine(delimiter);

            Console.WriteLine($"Переменная типа  {typeof(decimal)} занимает {sizeof(decimal)} Байт,\n" +
           $"и принимает значения в диапазоне: {decimal.MinValue} ... {decimal.MaxValue};");
            Console.WriteLine(delimiter);

            double a = 2;
            System.Int32 b = 3;
            Console.WriteLine(a.GetType());
            Console.WriteLine(b.GetType());
            Console.WriteLine(Object.Equals(a,b));
            
            if (a.GetType()== b.GetType())
            {
                Console.WriteLine("Типы равны");
            }
            else
            {
                Console.WriteLine( "Типы Не равны");
            }
            #endregion
            //тип любого значения всегда можно узнать при помощи GetType 
#endif
#if LITERALS
            Console.WriteLine(5.GetType()); //int
                Console.WriteLine(.5f.GetType()); //float
                Console.WriteLine(.5.GetType()); // double
                Console.WriteLine(5.0.GetType()); // double
                Console.WriteLine('+'.GetType()); // char

#endif





        }
        static readonly string delimiter = "\n---------------------------------------------\n";
    }
}
