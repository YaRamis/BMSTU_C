import ctypes
from ctypes import c_int, POINTER

lib = ctypes.CDLL("out/lib.so")

_left_cyclic_shift_by_k = lib.left_cyclic_shift_by_k
_left_cyclic_shift_by_k.argtypes = POINTER(c_int), c_int, c_int
_left_cyclic_shift_by_k.restype = c_int

_copy_perfect_squares = lib.copy_perfect_squares
_copy_perfect_squares.argtypes = POINTER(c_int), POINTER(c_int), c_int, POINTER(c_int)
_copy_perfect_squares.restype = c_int

def left_cyclic_shift_by_k(array, k):
    len_arr = len(array)
    new_arr = (c_int * len_arr)(*array)
    rc = _left_cyclic_shift_by_k(new_arr, len_arr, k)
    
    return list(new_arr), rc

def copy_perfect_squares(array):
    len_arr = len(array)
    new_arr = (c_int * len_arr)()
    main_arr = (c_int * len_arr)(*array)
    new_arr_len = (c_int)(len_arr)
    rc = _copy_perfect_squares(main_arr, new_arr, len_arr, new_arr_len)
    
    return list(new_arr), new_arr_len.value, rc
