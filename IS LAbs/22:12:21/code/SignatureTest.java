import java.security.*;

public class SignatureTest
{  public static void main(String[] args)
   {  try
      {  KeyPairGenerator keygen
            = KeyPairGenerator.getInstance("DSA");
         SecureRandom secrand = new SecureRandom();
         keygen.initialize(512, secrand);

         KeyPair keys1 = keygen.generateKeyPair();
         PublicKey pubkey1 = keys1.getPublic();
         PrivateKey privkey1 = keys1.getPrivate();

         KeyPair keys2 = keygen.generateKeyPair();
         PublicKey pubkey2 = keys2.getPublic();
         PrivateKey privkey2 = keys2.getPrivate();

         Signature signalg = Signature.getInstance("DSA");
         signalg.initSign(privkey2);
         String message
            = "Pay authors a bonus of Rs 20,000.";
         signalg.update(message.getBytes());
         
         byte[] signature = signalg.sign();
         
         Signature verifyalg = Signature.getInstance("DSA");
         verifyalg.initVerify(privkey2);
         verifyalg.update(message.getBytes());
         if (!verifyalg.verify(signature))
            System.out.print("Signature not Verified\n");
         else System.out.println("Signature Verified\n");
      }
      catch(Exception e)
      {  System.out.println("Error " + e);
      }
   }
}
