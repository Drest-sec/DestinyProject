public class Tache {
    String tache;


    public Tache(String tache){
        this.tache = tache;
    }

    public void afficherTache(){ System.out.println(tache); }
    public void supprimerTache(){ this.tache = null; }
}
