using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace shellsort
{
    public class ShellSort
    {
        private readonly int[] _array;

        public ShellSort(int[] array)
        {
            this._array = array;
        }

        public int[] Sort()
        {
            int i, j, inc, temp;
            var array_size = _array.Length;
            inc = 3;

            while (inc > 0)
            {
                for (i = 0; i < array_size; i++)
                {
                    j = i;
                    temp = _array[i];
                    while ((j >= inc) && (_array[j - inc] > temp))
                    {
                        _array[j] = _array[j - inc];
                        j = j - inc;
                    }
                    _array[j] = temp;
                }
                if (inc / 2 != 0)
                    inc = inc / 2;
                else if (inc == 1)
                    inc = 0;
                else
                    inc = 1;
            }

            return _array;
        }
    }
}
