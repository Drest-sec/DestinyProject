
import java.util.Scanner;
import java.util.ArrayList;
public class App{
    public static void main(String[] args){
        System.out.println("Bienvenue dans ma checklist");
        Scanner scanner = new Scanner(System.in);
        ArrayList<Tache> checklist = new ArrayList<Tache>();
        boolean continuer = true;
        Tache taches = new Tache("acheter des baguettes");
        checklist.add(taches);
        



        System.out.println("Que voulez vous faire ?");
        System.out.println("1. Ajouter une tâche"); 
        System.out.println("2. Afficher la checklist");
        System.out.println("3. Supprimer une tâche");
        System.out.println("4. Quitter");
        while(continuer){
        System.out.print("Veuillez choisir une option: ");
        int choice = scanner.nextInt();
        System.out.println("Vous avez choisi l'option: " + choice);    
                switch(choice){
                case 1:
                    System.out.println("Vous avez choisi Ajouter une tâche");
                    System.out.print("Entrez la tâche à ajouter: "); 
                    String nouvelleTache = scanner.nextLine(); // Consomme la nouvelle ligne restante String nouvelleTache = scanner.nextLine(); Tache tache = new Tache(nouvelleTache); checklist.add(tache);
                    Tache tache = new Tache(nouvelleTache); checklist.add(tache);
                    System.out.println("Tâche ajoutée: " + nouvelleTache);
                    break;
                case 2:
                    System.out.println("Vous avez choisi Afficher la checklist");
                    for(Tache checklistes : checklist){checklistes.afficherTache();}
                    break;
                case 3:
                    System.out.println("Vous avez choisi Supprimer une tâche"); 
                    System.out.print("Entrez le numéro de la tâche à supprimer: "); 
                    int numeroTache = scanner.nextInt(); if(numeroTache > 0 && numeroTache <= checklist.size()){ checklist.get(numeroTache - 1).supprimerTache(); checklist.remove(numeroTache - 1); System.out.println("Tâche supprimée."); } else { System.out.println("Numéro de tâche invalide."); } break;
                case 4:
                    System.out.println("Vous avez choisi de quitter");
                    continuer = false;
                    System.out.println("Au revoir !"); 
                    break; 
                    default: System.out.println("Choix invalide, veuillez réessayer.");
                

            }


    }
}
}