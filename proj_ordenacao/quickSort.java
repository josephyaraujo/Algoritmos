import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.FileReader;

public class quickSort{
    //Função que mescla os subarrays ordenados
    static int particao(int a[], int primeiro, int ultimo){ //a[] - array principal | primeiro e ultimo - indices do array
        int pivo = a[ultimo];  //O pivo que vai ser utilizado como elemento central de comparação é o ultimo elemento do array
         
        int i = primeiro - 1; //Menor indice do array

        for (int j = primeiro; j <= ultimo - 1; j++){ //Começa do primeiro indice e vai ate o ultimo antes do pivo
            if (a[j] < pivo){ //Se o elemento for menor que o pivo ele fica a esquerda do pivo
                i++; //Soma 1 ao indice i
                int guarda = a[i]; //Guarda recebe elemento do indice i (se todos os elementos menores ja estiverem a esquerda do pivo, esse pedaço do codigo guarda os valores no mesmo lugar)
                a[i] = a[j];  //Indice i recebe elemento do indice j
                a[j] = guarda; //Indice J recebe antigo elemento do indice I
                //O indice I serve para manter a troca entre o menor elemento com o maior, sempre colocando os menores a esquerda e os maiores a direita
            }
        }

        //Quando percorreu todo o array, pega o pivo e o coloca na posição certa do array, com os menores a esquerda e os maiores a direita
        int guarda = a[i+1]; 
        a[i+1] = a[ultimo];
        a[ultimo] = guarda;

        return i + 1; //Retorna posição onde o pivo foi guardado
    }

    //Função recursiva que divide o array ao meio até não poder ser mais dividido, ou seja, até ter apenas um elemento
    static void sort(int a[], int primeiro, int ultimo){
        if (primeiro < ultimo) { //Se o primeiro indice for menor que o ultimo indice, ou seja, quando tiver apenas um elemento
            int pi = particao(a, primeiro, ultimo);
            
            sort(a, primeiro, pi - 1); //Subarray que inicia antes do pivo
            sort(a, pi + 1, ultimo); //Subarray que começa depois do pivo
        }
    }

    public static void main(String[] args){
        List<Integer> lista = new ArrayList<>();
        try(BufferedReader br = new BufferedReader(new FileReader(args[0]))){ //leitura do arquivo
            String line = br.readLine(); //linha por linha
            
            while (line != null){
                lista.add(Integer.parseInt(line)); //guarda linha na lista transformando para inteiro
                line = br.readLine();     
            }

            int[] array = lista.stream().mapToInt(i -> i).toArray();

            long tempoInicial = System.currentTimeMillis(); //tempo inicial antes da execução do código
            sort(array, 0, array.length - 1); //Primeira chamada do quick Sort

            System.out.print("tempo de execução:" + (System.currentTimeMillis() - tempoInicial) + " milisegundos \n"); 
            for (int i = 0; i < array.length; i++){
                System.out.println(array[i]);
            }
        } catch (IOException e){
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }
    }        
} 