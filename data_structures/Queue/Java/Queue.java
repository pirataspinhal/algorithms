package eda;

import java.util.Arrays;
import java.util.Scanner;

class Queue {

	private String[] array;
	private int tail;
	private static final String FULL = "full";
	private static final String EMPTY = "empty";

	public Queue(int size) {
			this.array = new String[size];
			this.tail = -1;
		}

	public void add(String value) {
		if (!isFull()) {
			tail++;
			array[tail] = value;
		} else {
			System.out.println(FULL);
		}
	}

	public void remove() {
		if (!isEmpty()) {
			shift();
			tail--;
		} else {
			System.out.println(EMPTY);
		}
	}

	private void shift() {
		for (int i = 1; i <= tail; i++) {
			this.array[i - 1] = this.array[i];
		}

	}

	public String print() {
		if (isEmpty()) {
			return EMPTY;
		}
		String saida = "";
		for (int i = 0; i <= tail; i++) {
			saida += array[i] + " ";
		}
		return saida.trim();

	}

	public boolean isEmpty() {
		return (tail == -1);
	}

	public boolean isFull() {
		return (tail == array.length - 1);
	}

	public static void main(String[] args) {

		Scanner ler = new Scanner(System.in);
		int size = ler.nextInt();
		// Limpar o buffer
		ler.nextLine();
		Queue fila = new Queue(size);
		String[] op;
		do {
			op = ler.nextLine().split(" ");
			switch (op[0]) {
			case "remove":
				fila.remove();
				break;
			case "print":
				System.out.println(fila.print());
				break;
			case "element":
				System.out.println(fila.element());
				break;
			case "end":
				break;
			case "add":
				fila.add(op[1]);
				break;
			default:
				break;
			}

		} while (!op[0].equals("end"));
	}

	private String element() {
		if (isEmpty())
			return EMPTY;
		return this.array[0];
	}

}
