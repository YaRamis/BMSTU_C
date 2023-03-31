from tkinter import *
from tkinter import messagebox
from funcs import *

root = Tk()

root.geometry('780x240')
root.resizable(False, False)

lab1_arr = Label(font=('TimesNewRoman', 15), text='ARR = ')
lab_k = Label(font=('TimesNewRoman', 15), text='k = ')
ent1_arr = Entry(width=24, font=('TimesNewRoman', 12))
ent_k = Entry(width=10, font=('TimesNewRoman', 12))
but_to_shift = Button(width=24, text='Сдвиг на k влево -->', bd=5, font=('TimesNewRoman', 15))
lab_shifted_arr = Label(width=24, font=('TimesNewRoman', 12), bg='gray', fg='white')

sep = Label(text='--------------------------------------------------------------'
                 '-----', height=1, font=('TimesNewRoman', 20), fg='gray')

lab2_arr = Label(font=('TimesNewRoman', 15), text='ARR = ')
ent2_arr = Entry(width=24, font=('TimesNewRoman', 12))
but_to_find_perf_sq = Button(width=24, text='Полные квадраты -->', bd=5, font=('TimesNewRoman', 15))
lab_perf_squares_arr = Label(width=24, font=('TimesNewRoman', 12), bg='gray', fg='white')


def shift_arr(event):
    array = ent1_arr.get().split(' ')
    k = int(ent_k.get())
    for i in range(len(array)):
        array[i] = int(array[i])
    array, rc = left_cyclic_shift_by_k(array, k)
    for i in range(len(array)):
        array[i] = str(array[i])
    if rc == 0:
        lab_shifted_arr['text'] = ' '.join(array)
    elif rc == 1:
        lab_shifted_arr['text'] = "ARR PTR NULL"
    elif rc == 2:
        lab_shifted_arr['text'] = "ARR SIZE ERROR"
    elif rc == 3:
        lab_shifted_arr['text'] = "SHIFT NUM ERROR"

def get_perf_sq(event):
    array = ent2_arr.get().split(' ')
    for i in range(len(array)):
        array[i] = int(array[i])
    new_array, new_arr_len, rc = copy_perfect_squares(array)
    res_array = [0] * new_arr_len
    for i in range(new_arr_len):
        res_array[i] = str(new_array[i])
    if rc == 0:
        lab_perf_squares_arr['text'] = ' '.join(res_array)
    elif rc == 1:
        lab_perf_squares_arr['text'] = "ARR PTR NULL"
    elif rc == 2:
        lab_perf_squares_arr['text'] = "ARR SIZE ERROR"
    elif rc == 4:
        lab_perf_squares_arr['text'] = "NO PERFECT SQUARES"

but_to_shift.bind('<Button-1>', shift_arr)
but_to_find_perf_sq.bind('<Button-1>', get_perf_sq)

lab1_arr.grid(row=0, column=0)
lab_k.grid(row=1, column=0)
ent1_arr.grid(row=0, column=1, columnspan=2, padx=10, pady=15)
ent_k.grid(row=1, column=1, columnspan=2, padx=10, pady=15)
but_to_shift.grid(row=0, rowspan=2, column=3)
lab_shifted_arr.grid(row=0, rowspan=2, column=4, columnspan=2, padx=10, pady=15)

sep.grid(row=2, rowspan=2, column=0, columnspan=6)

lab2_arr.grid(row=4, column=0)
ent2_arr.grid(row=4, column=1, columnspan=2, padx=10, pady=15)
but_to_find_perf_sq.grid(row=4, column=3)
lab_perf_squares_arr.grid(row=4, column=4, columnspan=2, padx=10, pady=15)

root.mainloop()
