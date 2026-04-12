

public class Contact { 
    String nom;
    String prenom;
    String numero;

    public Contact(String nom, String prenom, String numero){
        this.nom = nom;
        this.prenom = prenom;
        this.numero = numero;
    }

    public void afficher(){
        System.out.println("Nom: " + nom + ", Prenom: " + prenom + ", Numero: " + numero);
      
    }   

    
    boolean rechercher(String nom) {
        return this.nom.equalsIgnoreCase(nom);
    }

    public String getNom() {
        return nom;
    }
    public String getPrenom() {
        return prenom;
    }

    public String getNumero() {
        return numero;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }
    
    public void setNumero(String numero) {
        this.numero = numero;
    }
    
    public void supprimer(){
        this.nom = null;
        this.prenom = null;
        this.numero = null;
    }
}
