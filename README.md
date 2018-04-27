#   A p p o r x T S P  
  
 A u t h o r :   Y o n g q i n g   L i a n g  
  
 # #   1 .   S o u r c e   c o d e s  
  
 -   * * m a i n . c p p * * :   T h e   e n t r y   o f   t h e   p r o g r a m .  
 -   * * u t i l s * * :   S o m e   u s e f u l   f u n c t i o n s .  
 -   * * N o d e * * :   D e c l a r e   t h e   n o d e   o f   t h e   s e a r c h   t r e e .  
 -   * * A l p h a - B e t a   P r u n i n g * * :   T h e   a l p h a - b e t a   p r u n i n g   a l g o r i t h m   t o   s o l v e   T S P   a p p r o x i m a t e l y .  
 -   * * G r e e d y   S e a r c h * * :   T h e   g r e e d y   s e a r c h   a l g o r i t h m     t o   s o l v e   T S P   a p p r o x i m a t e l y .   I t   i s   a   s p e c i a l   c a s e   o f   a l p h a - b e t a   p r u n i n g   w h e n   a l p h a = = 1   a n d   b e t a = = 0 .  
  
 # #   2 .   A r g u m e n t s  
  
 1 .   * * D a t a I d * * :   I n t e g e r .   T h e   i n d e x   o f   t h e   r e a l   d a t a .   ( C a n   n o t   b e   N U L L )  
 2 .   * * A l p h a * * :   I n t e g e r .   T h e   n u m b e r   o f   t h e   n o d e s   w h i c h   w i l l   b e   e r g o d i c .   ( D e f a u l t :   5 0 )  
 3 .   * * B e t a * * :   I n t e g e r .   T h e   d e p t h   o f   t h e   f u r t h e r   e v a l u a t i o n .   ( D e f a u l t :   2 ) 