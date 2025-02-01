import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.FileReader;

public class selectionSort{
    public static void main(String[] args){
        List<Integer> lista = new ArrayList<>(); //Criação da lista para guardar os valores
        try(BufferedReader br = new BufferedReader(new FileReader("100Numeros.txt"))){ //leitura do arquivo
            String line = br.readLine(); //linha por linha
            while (line != null){
                lista.add(Integer.parseInt(line)); //guarda linha na lista transformando para inteiro
                line = br.readLine();     
            }

            int[] array = lista.stream().mapToInt(i -> i).toArray();

            long tempoInicial = System.currentTimeMillis(); //tempo inicial antes da execução do código
            for (int i = 0; i < array.length; i++){ //Percorre todo o array
                int indiceDoMenor = i; // Recebe o índice do valor atual 
                for (int j = i + 1; j < array.length; j++){ // Começa do numero da frente e vai ate o final do array
                    if (array[j] < array[indiceDoMenor]){ //Se valor no índice j for menor que o anterior
                        indiceDoMenor = j; //Indice do menor recebe indice do atual, pois o menor é o atual
                    }
                }
                //Depois que acha o menor de todos, traz ele pra frente
                int guarda = array[i]; //Variável guarda recebe valor de comparação inicial que estava no índice i 
                array[i] = array[indiceDoMenor]; //Guarda o menor valor encontrado no indice inicial
                array[indiceDoMenor] = guarda; //Guarda o valor de comparação inicial na posição antiga do menor valor encontrado, os trocando de posição  
            }
            System.out.print("tempo de execução:" + (System.currentTimeMillis() - tempoInicial) + " milisegundos \n"); 
        } catch (IOException e){
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }
    }        
} 
