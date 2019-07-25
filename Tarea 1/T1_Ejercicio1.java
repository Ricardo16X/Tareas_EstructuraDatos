import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Scanner;

public class T1_Ejercicio1 {
	public static void main(String[] args) {
		// Variables
		String fechaPartes[];
		int valores[];
		Scanner lector = new Scanner(System.in);
		// Mostrar día de la semana, por fechas		
		try {
			System.out.println("Adivinando el dia de la semana de la fecha\n" + "Ingresa una fecha: (dd/mm/yyyy)");
			fechaPartes = lector.next().split("/");
			lector.close();
			valores = new int[3];
			for (int i = 0; i < fechaPartes.length; i++) {
				valores[i] = Integer.parseInt(fechaPartes[i]);
			}
			// Validación de fecha---------------------
			Calendar calendar = Calendar.getInstance();
			calendar.setLenient(false);
			calendar.set(Calendar.DAY_OF_MONTH, valores[0]);
			calendar.set(Calendar.MONTH, valores[1] - 1); // [0,...,11]
			calendar.set(Calendar.YEAR, valores[2]);
			Date date = (Date) calendar.getTime();
			SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
			sdf.format(date);
			System.out.println("El dia de la semana de la fecha es : " + diaSemana(valores[0], valores[1], valores[2]));
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("Ha ocurrido un error con " + e.getMessage());
		}
	}

	private static String diaSemana(int dia, int mes, int year) {
		// Validar Fecha
		if (year >= 1700) { // Validar el año
			String dias[] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
			int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
			if (mes < 3) {
				year -= 1;
			}
			return dias[(int) ((year + year / 4 - year / 100 + year / 400 + t[mes - 1] + dia) % 7)];
		} else {
			return "Solo desde los 1700 en adelante...";
		}
	}
}