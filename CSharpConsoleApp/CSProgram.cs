//C# 

#define Test
#undef Test

using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



/// <summary>
/// C# Test Collects
/// </summary>
namespace CSharpConsoleApp
{

    /// <summary>
    ///  Main Function
    /// </summary>
    class CSProgram
    {
        /// <summary>
        /// 重构if...else
        /// </summary>
        /// <param name="args"></param>
        /// 
        public static string DoSomething3(string something)
        {
            if (something == "a") return "aaa";
          
            if (something == "bb") return "bbb";

            return "defaulut things";
        }
        public static void DoSomething2(string something)
        {
            if (something == "a")
            {
                Console.WriteLine("aaa");
                return;
            }
            if (something == "bb")
            {
                Console.WriteLine("bbb");
                return;
            }
           
            Console.WriteLine("defaulut things");
        }
        public static void DoSomething1(string something)
        {
            if (something=="a")
            {
                Console.WriteLine("aaa");
            }
            else if(something=="bb")
            {
                Console.WriteLine("bbb");
            }
            else
            {
                Console.WriteLine("defaulut things");
            }
        }
        ///三元
        public static string DoSomething0(int age)
        {
            if (age > 3) throw new ArgumentException();
            if (age < 1) throw new ArgumentException();
            return age == 2 ? "aaaa" : "bbbbb";
        }
        public static void DoSomething(string something)
        {
            var dic = new Dictionary<string, Action>();
            dic["a"] = () => { Console.WriteLine("aaa"); };
            dic["bbb"] = () => { Console.WriteLine("bbb"); };

            dic[something].Invoke();
        }

        static void Main(string[] args)
        {
            Console.WriteLine("C#测试");
            GraphicEditor graphic = new GraphicEditor();
            graphic.DrawShape(new Plane());
            graphic.DrawShape(new Cube());
            graphic.DrawShape(new Triangel());

        }




    }
    ///<summary>
    ///Code performance analysis
    ///</summary>
    class CodePerformanceTest
    {
        public void TestCodePerformance()
        {
            Stopwatch sp = new Stopwatch();

            sp.Start();
            TestForeach();
            sp.Stop();
            Console.WriteLine($"It took {sp.ElapsedMilliseconds} milliseconds");
        }

        List<string> strList = new List<string>() { "龘（dá）@", "靐（bìng）", "齉 （nàng）@", "齾 （yà ）", "麤 （cū)@", "龖（dá）", "龗 （líng ）", "鱻 （xiān）@", "爩 （yù）", "a" };
        //int num = 10000;
        public void TestFor()
        {
            string result = null;
            for (int i = 0; i < strList.Count; i++)
            {
                if (strList[i].IndexOf("@")==-1)
                {
                    result += i.ToString();
                }
               
            }
        }
        public void TestForeach()
        {
            //string result = null;
            foreach (var item in strList)
            {
                if (item.Contains("y"))
                {
                    Console.WriteLine(item);
                }
            }
        }
        public void TestLambda()
        {
          var getList =  strList.Where(item => {  return item.Contains("y"); });
            foreach (var item in getList)
            {
                Console.WriteLine(item);
            }
        }
        public void TestLINQ()
        {
            int[] number = { 2, 4, 5, 7, 8, 10 };
            List<int> nub =new List<int>() { 2, 4, 5, 7, 8, 10 };
            //IEnumerable<int> findNum = from n in nub where n < 8 select n;
            IEnumerable<string> findStr = from item in strList where item.Length < 6 select item;
            foreach (var item in findStr)
            {
                Console.WriteLine("{0}",item);
            }
        }
    }



    /// <summary>
    /// DataStruct:usual DataStructs：Array，ArrayList，List，LinkedList，Queue，Stack，Dictionary<K,T>
    /// https://blog.csdn.net/jia18337935154/article/details/87880529
    /// </summary>
    class CDataStructs
    {




        ///Dict

        ///Calculate Signs:+ - * /  %   |  &
        // |
        //private static readonly int cal_OR = 1;

        public bool Calculate(bool x, bool y)
        {
            return x | y;
        }

    }

    /// <summary>
    /// DataTypes: ValueTypes && ReferenceTypes
    /// ValueT: bool  int   float  double   char  enum    
    /// ReferenceT :  Class String  Array  Interface  Delegate
    /// </summary>
    public partial class CDataTypes_Value
    {

        //Enum
        enum MyEnum
        {
            None = 0,
            One,
            Two,
            Three,
        }
    }
    public partial class CDataTypes_Reference
    {


    }

    public partial class CDataTypes_Reference
    {


    }

    /// <summary>
    /// Generic Class
    /// https://cloud.tencent.com/developer/article/1622255#:~:text=C%23%E4%B9%9F%E5%8F%AF%E4%BB%A5%E5%A3%B0%E6%98%8E%E4%B8%80%E4%B8%AA%E6%96%B9%E6%B3%95%E4%B8%BA%E6%B3%9B%E5%9E%8B%E6%96%B9%E6%B3%95%EF%BC%8C%E6%96%B9%E6%B3%95%E7%9A%84%E6%B3%9B%E5%9E%8B%E5%A3%B0%E6%98%8E%E6%98%AF%E5%A3%B0%E6%98%8E%E5%9C%A8%E6%96%B9%E6%B3%95%E5%90%8D%E7%9A%84%E5%90%8E%E9%9D%A2%EF%BC%8C%E5%8F%82%E6%95%B0%E5%88%97%E8%A1%A8%E7%9A%84%E5%89%8D%E6%96%B9%E3%80%82%20public%20void%20TemplateMethod%20%3CT%3E%28T%20arg%29%3B%20public,T%20TemplateMethod1%20%3CT%3E%28%29%3B%20public%20T%20TemplateMethod2%20%3CT%3E%28T%20arg%29%3B
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public partial class CGeneric<T>
    {
        public T genericCInstance;

        public void SetGeneric(T t)
        {
            genericCInstance = t;
        }
        public T GetGeneric()
        {
            return genericCInstance;
        }
    }

    /// <summary>
    /// Interface
    /// 接口使用interface 关键字进行定义，可由方法、属性、事件、索引器或这四种成员类型的任意组合构成
    /// </summary>
    interface IInsert
    {
        void InsertFunc();
    }
    interface IDelete
    {
        void DeleteFunc();
    }
    interface IShow
    {
        void ShowkFunc();
    }
    interface IAlter
    {
        void AlterFunc();
    }

    /// <summary>
    /// BaseClass
    /// 抽象方法没有实现，所以方法定义后面是分号，而不是常规的方法块.抽象类的派生类必须实现所有抽象方法。 当抽象类从基类继承虚方法时，抽象类可以使用抽象方法重写该虚方法
    /// </summary>
    public abstract class CBase
    {

    }


    class CGC
    {
        public void MakeGabage()
        {
            Version version;
            for (int i = 0; i < 1000; i++)
            {
                version = new Version();
            }
        }
        public void TestGC()
        {
            Console.WriteLine("gc before have{0:N0}", GC.GetTotalMemory(false));
            GC.Collect();
            Console.WriteLine($"gc after have{0:N0}", GC.GetTotalMemory(true));
        }
    }


    /// <summary>
    /// 开闭原则：对修改关闭,对扩展开放
    /// </summary>
    
    //调用方(用户,使用方)-对修改关闭
    public class GraphicEditor
    {
        public void DrawShape(Shape s)
        {
            s.Draw();
        }
    }

   //提供方(被调用的类)-对扩展开放
   public  abstract class Shape
    {
        public int m_Type;
        public abstract void Draw();

    }

    public class Cube : Shape
    {
        public Cube()
        {
            m_Type = 1;
        }

        public override void Draw()
        {
            Console.WriteLine("正方体");
        }
    }

    public class Triangel : Shape
    {
        public Triangel() { m_Type = 2; }

        public override void Draw()
        {
            Console.WriteLine("三角");
        }
    }

    public class Plane : Shape {public Plane() { m_Type = 3; } public override void Draw() { Console.WriteLine("平面"); } };

}

