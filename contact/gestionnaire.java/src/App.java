import java.util.ArrayList;
import java.util.Scanner;
public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        Contact c = new Contact("Doe", "John", "1234567890");
        boolean running = true;
        ArrayList<Contact> listeContacts = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        listeContacts.add(c);


        System.out.println("-----------------------------------------------------------");
        System.out.println("1: Ajouter un contact");
        System.out.println("2: Afficher les contacts");
        System.out.println("3: Rechercher un contact");
        System.out.println("4: Supprimer un contact");
        System.out.println("5: Quitter");

        while(running) {
        System.out.print("Veuillez choisir une option: ");
        int choice = scanner.nextInt();
        System.out.println("Vous avez choisi l'option: " + choice);
        switch(choice) {
            case 1:
                System.out.println("Ajouter un contact");
                System.out.print("Entrez le nom: ");
                String name = scanner.next();
                if(name.isEmpty()) { System.out.println("saisissez un nom qui n'est pas vide.");name = scanner.next();  } 
                System.out.print("Entrez le prenom: ");
                String prenom = scanner.next();
                System.out.print("Entrez le numero: ");
                String numero = scanner.next();
                if(numero.length() == 10) {
                    Contact newContact = new Contact(name, prenom, numero);
                    listeContacts.add(newContact);
                    System.out.println("Contact ajouté avec succès!");
                } else {
                    System.out.println("Le numéro doit comporter 10 chiffres.");
                    break;
                }
                

                break;
            case 2:
                System.out.println("Afficher les contacts");
                for(Contact contact : listeContacts) {
                    contact.afficher();
                }
                break;
            case 3:
                System.out.println("Rechercher un contact");
                System.out.print("Entrez le nom à rechercher: ");
                String searchName = scanner.next();
                boolean found = false;
                for(Contact contact : listeContacts) {
                    if(contact.rechercher(searchName)) {
                        contact.afficher();
                        found = true;
                    }
                }
                if(!found) {
                    System.out.println("Contact non trouvé.");
                }
                break;
            case 4:
                System.out.println("Supprimer un contact");
                System.out.print("Entrez le nom du contact à supprimer: ");
                String deleteName = scanner.next();
                boolean deleted = false;
                for(Contact contact : listeContacts) {
                    if(contact.rechercher(deleteName)) {
                        contact.supprimer();
                        listeContacts.remove(contact);
                        System.out.println("Contact supprimé avec succès!");
                        deleted = true;
                        break;
                    }
                }                if(!deleted) {
                    System.out.println("Contact non trouvé.");
                }
                break;
            case 5:
                System.out.println("Quitter");
                running = false;
                break;
            default:
                System.out.println("Option invalide, veuillez réessayer.");

            scanner.close();
        }

    }
}
}
