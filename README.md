Задание состоит из последовательности связанных между собой пунктов.

## Главная задача
для каждого пункта решить сформулированную в нём задачу наиболее эффективно**.  Для подавляющего, кроме, возможно, первого пункта применение циклов не будет считаться корректным решением.

## Ход работы
- [x] Создать вектор v1 размером от 500 до 1000 элементов, число элементов не известно до запуска программы. Элементами вектора являются экземпляры класса из Л.Р. №2 имеющие произвольные(случайные) значения. В случае необходимости этот класс должен быть доработан для возможности решать поставленные в этой ЛР задачи.
- [x] Создать вектор v2, поместив в него последние 200 элементов вектора v1. Рассмотрите решение для произвольных b и e, которые задают позиции первого и последнего копируемых элементов.
- [x] Сформировать список list1, поместив в него первые n (от 20 до 50) наибольших элементов вектора v1 (указанные элементы должны быть отсортированы до помещения их в список).
- [x] Сформировать список list2, поместив в него последние n (от 20 до 50) наименьших элементов вектора v2, порядок элементов не важен.
- [x] Удалить из векторов v1 и v2 перемещенные элементы. Скорректируйте размеры векторов после удаления из них элементов.
- [x] Для списка list1 найти элемент со средним значением. Перегруппировать элементы списка так, чтобы в начале оказались все элементы, большие среднего значения.
- [x] Удалите из списка list2 все нечётные элементы (или используйте другой критерий, который однозначно делит экземпляры вашего класса на два непересекающихся множества).
- [x] Создайте вектор v3 из элементов, которые присутствуют и в векторе v1 и в векторе v2.
- [x] Для списков list1 и list2 из списка с большим числом элементов удалите первые n так, чтобы оба списка имели бы одинаковый размер. Сформируйте из них список list3, который будет хранить пары <первый элемент списка list1, первый элемент списка list2>, <второй элемент списка list1, второй элемент списка list2>  и т. д.
- [x] Решите предыдущую задачу для векторов v1 и v2 без предварительного приведения векторов к одному размеру. Пар с пустыми значениями быть не должно.
- [x] Оформить отчёт и загрузить по принятым правилам.


** Будем под эффективностью понимать решение, использующее минимальный код, и не выполняющее лишних действий.

## Решение
Исходный код к заданию 

## Вывод программы
```
1. Создать вектор v1 размером от 500 до 1000 элементов, число элементов не известно до запуска программы. Элементами вектора являются экземпляры класса из Л.Р. №2 имеющие произвольные(случайные) значения. В случае необходимости этот класс должен быть доработан для возможности решать поставленные в этой ЛР задачи.
[v1]: 778 618 827 340 978 935 261 912 260 87 518 702 239 419 62 325 642 670 585 97 838 782 454 960 284 988 799 157 276 521 483 71 797 783 516 200 704 597 777 228 90 590 234 343 673 323 219 616 695 133 255 922 271 159 988 655 137 843 68 403 571 433 1018 968 91 552 810 26 469 151 981 677 12 1017 700 380 238 583 502 919 825 159 664 843 639 91 1014 7 485 101 117 433 881 876 676 257 884 77 774 394 454 192 685 248 154 435 723 894 966 696 501 939 852 277 851 423 789 626 53 223 959 371 727 918 415 105 533 986 379 808 212 154 645 234 525 408 897 541 91 216 444 270 609 230 906 773 16 705 72 716 845 658 939 572 471 255 787 710 96 940 723 573 738 294 106 216 296 142 530 327 48 989 1024 833 705 141 427 855 138 324 55 536 283 498 915 121 691 535 937 725 341 785 482 1005 965 42 533 223 110 296 734 684 725 817 805 857 837 755 124 527 147 128 990 551 523 421 375 505 1007 806 27 362 889 306 459 717 808 989 258 837 30 151 86 111 558 675 694 296 236 187 98 1004 610 362 875 292 363 579 538 694 753 120 962 973 157 782 318 538 276 266 370 186 158 474 540 366 569 103 301 306 682 668 777 1010 315 411 819 669 964 164 193 749 28 251 57 616 29 286 570 202 246 394 39 877 477 674 13 937 454 194 459 902 14 294 571 97 472 883 95 739 834 425 356 222 660 221 436 33 564 375 248 574 5 755 264 729 105 342 1014 1018 848 351 205 105 82 921 165 523 279 684 514 372 146 281 135 927 732 824 349 394 535 534 920 858 471 718 747 1013 148 784 729 719 590 199 644 269 198 653 381 75 230 121 698 722 341 403 916 523 690 652 549 245 56 498 54 106 828 295 953 235 193 753 757 1008 1017 234 203 681 343 507 661 1016 343 495 439 1004 142 215 28 298 176 13 650 412 749 77 400 494 411 496 706 557 369 53 553 224 679 106 341 892 322 443 993 79 55 672 65 451 974 916 998 501 791 352 756 960 448 561 399 515 954 527 950 474 291 817 864 219 56 146 1017 694 45 916 646 357 33 992 52 64 123 498 671 613 922 105 491 282 38 274 471 51 563 27 189 66 175 184 624 418 108 658 994 207 231 29 516 624 742 806 1012 608 108 974 978 590 674 874 458 392 706 899 40 213 687 632 571 315 

2. Создать вектор v2, поместив в него последние 200 элементов вектора v1. Рассмотрите решение для произвольных b и e, которые задают позиции первого и последнего копируемых элементов.
[v2]: 564 375 248 574 5 755 264 729 105 342 1014 1018 848 351 205 105 82 921 165 523 279 684 514 372 146 281 135 927 732 824 349 394 535 534 920 858 471 718 747 1013 148 784 729 719 590 199 644 269 198 653 381 75 230 121 698 722 341 403 916 523 690 652 549 245 56 498 54 106 828 295 953 235 193 753 757 1008 1017 234 203 681 343 507 661 1016 343 495 439 1004 142 215 28 298 176 13 650 412 749 77 400 494 411 496 706 557 369 53 553 224 679 106 341 892 322 443 993 79 55 672 65 451 974 916 998 501 791 352 756 960 448 561 399 515 954 527 950 474 291 817 864 219 56 146 1017 694 45 916 646 357 33 992 52 64 123 498 671 613 922 105 491 282 38 274 471 51 563 27 189 66 175 184 624 418 108 658 994 207 231 29 516 624 742 806 1012 608 108 974 978 590 674 874 458 392 706 899 40 213 687 632 571 315 

3. Сформировать список list1, поместив в него первые n (от 20 до 50) наибольших элементов вектора v1 (указанные элементы должны быть отсортированы до помещения их в список).
[list1]: 1024 1018 1018 1017 1017 1017 1016 1014 1014 1013 1012 1010 1008 1007 1005 1004 1004 998 994 993 992 990 989 989 988 988 986 981 978 978 974 974 973 968 966 965 

4. Сформировать список list2, поместив в него последние n (от 20 до 50) наименьших элементов вектора v2, порядок элементов не важен.
[list2]: 5 13 27 28 29 33 38 40 45 51 52 53 54 55 56 56 64 65 66 75 77 79 82 105 105 105 106 106 108 108 121 123 135 142 146 146 148 165 175 176 184 189 193 198 199 203 205 207 

5. Удалить из векторов v1 и v2 перемещенные элементы. Скорректируйте размеры векторов после удаления из них элементов.
[v1]: 778 618 827 340 935 261 912 260 87 518 702 239 419 62 325 642 670 585 97 838 782 454 960 284 799 157 276 521 483 71 797 783 516 200 704 597 777 228 90 590 234 343 673 323 219 616 695 133 255 922 271 159 655 137 843 68 403 571 433 91 552 810 26 469 151 677 12 700 380 238 583 502 919 825 159 664 843 639 91 7 485 101 117 433 881 876 676 257 884 77 774 394 454 192 685 248 154 435 723 894 696 501 939 852 277 851 423 789 626 53 223 959 371 727 918 415 105 533 379 808 212 154 645 234 525 408 897 541 91 216 444 270 609 230 906 773 16 705 72 716 845 658 939 572 471 255 787 710 96 940 723 573 738 294 106 216 296 142 530 327 48 833 705 141 427 855 138 324 55 536 283 498 915 121 691 535 937 725 341 785 482 42 533 223 110 296 734 684 725 817 805 857 837 755 124 527 147 128 551 523 421 375 505 806 27 362 889 306 459 717 808 258 837 30 151 86 111 558 675 694 296 236 187 98 610 362 875 292 363 579 538 694 753 120 962 157 782 318 538 276 266 370 186 158 474 540 366 569 103 301 306 682 668 777 315 411 819 669 964 164 193 749 28 251 57 616 29 286 570 202 246 394 39 877 477 674 13 937 454 194 459 902 14 294 571 97 472 883 95 739 834 425 356 222 660 221 436 33 564 375 248 574 5 755 264 729 105 342 848 351 205 105 82 921 165 523 279 684 514 372 146 281 135 927 732 824 349 394 535 534 920 858 471 718 747 148 784 729 719 590 199 644 269 198 653 381 75 230 121 698 722 341 403 916 523 690 652 549 245 56 498 54 106 828 295 953 235 193 753 757 234 203 681 343 507 661 343 495 439 142 215 28 298 176 13 650 412 749 77 400 494 411 496 706 557 369 53 553 224 679 106 341 892 322 443 79 55 672 65 451 916 501 791 352 756 960 448 561 399 515 954 527 950 474 291 817 864 219 56 146 694 45 916 646 357 33 52 64 123 498 671 613 922 105 491 282 38 274 471 51 563 27 189 66 175 184 624 418 108 658 207 231 29 516 624 742 806 608 108 590 674 874 458 392 706 899 40 213 687 632 571 315 
[v2]: 564 375 248 574 755 264 729 342 1014 1018 848 351 921 523 279 684 514 372 281 927 732 824 349 394 535 534 920 858 471 718 747 1013 784 729 719 590 644 269 653 381 230 698 722 341 403 916 523 690 652 549 245 498 828 295 953 235 753 757 1008 1017 234 681 343 507 661 1016 343 495 439 1004 215 298 650 412 749 400 494 411 496 706 557 369 553 224 679 341 892 322 443 993 672 451 974 916 998 501 791 352 756 960 448 561 399 515 954 527 950 474 291 817 864 219 1017 694 916 646 357 992 498 671 613 922 491 282 274 471 563 624 418 658 994 231 516 624 742 806 1012 608 974 978 590 674 874 458 392 706 899 213 687 632 571 315 

6. Для списка list1 найти элемент со средним значением. Перегруппировать элементы списка так, чтобы в начале оказались все элементы, большие среднего значения.
[list1]: 994 993 992 990 989 989 988 988 986 981 978 978 974 974 973 968 966 965 1024 1018 1018 1017 1017 1017 1016 1014 1014 1013 1012 1010 1008 1007 1005 1004 1004 998 

7. Удалите из списка list2 все нечётные элементы (или используйте другой критерий, который однозначно делит экземпляры вашего класса на два непересекающихся множества).
[list2]: 28 38 40 52 54 56 56 64 66 82 106 106 108 108 142 146 146 148 176 184 198 

8. Создайте вектор v3 из элементов, которые присутствуют и в векторе v1 и в векторе v2.
[v3]: 5 7 12 13 13 14 16 26 27 27 28 28 29 29 30 33 33 38 39 40 42 45 48 51 52 53 53 54 55 55 56 56 57 62 64 65 66 68 71 72 75 77 77 79 82 86 87 90 91 91 91 95 96 97 97 98 101 103 105 105 105 105 106 106 106 108 108 110 111 117 120 121 121 123 124 128 133 135 137 138 141 142 142 146 146 147 148 151 151 154 154 157 157 158 159 159 164 165 175 176 184 186 187 189 192 193 193 194 198 199 200 202 203 205 207 212 213 215 216 216 219 219 221 222 223 223 224 228 230 230 231 234 234 234 235 236 238 239 245 246 248 248 251 255 255 257 258 260 261 264 266 269 270 271 274 276 276 277 279 281 282 283 284 286 291 292 294 294 295 296 296 296 298 301 306 306 315 315 318 322 323 324 325 327 340 341 341 341 342 343 343 343 349 351 352 356 357 362 362 363 366 369 370 371 372 375 375 379 380 381 392 394 394 394 399 400 403 403 408 411 411 412 415 418 419 421 423 425 427 433 433 435 436 439 443 444 448 451 454 454 454 458 459 459 469 471 471 471 472 474 474 477 482 483 485 491 494 495 496 498 498 498 501 501 502 505 507 514 515 516 516 518 521 523 523 523 525 527 527 530 533 533 534 535 535 536 538 538 540 541 549 551 552 553 557 558 561 563 564 569 570 571 571 571 572 573 574 579 583 585 590 590 590 597 608 609 610 613 616 616 618 624 624 626 632 639 642 644 645 646 650 652 653 655 658 658 660 661 664 668 669 670 671 672 673 674 674 675 676 677 679 681 682 684 684 685 687 690 691 694 694 694 695 696 698 700 702 704 705 705 706 706 710 716 717 718 719 722 723 723 725 725 727 729 729 732 734 738 739 742 747 749 749 753 753 755 755 756 757 773 774 777 777 778 782 782 783 784 785 787 789 791 797 799 805 806 806 808 808 810 817 817 819 824 825 827 828 833 834 837 837 838 843 843 845 848 851 852 855 857 858 864 874 875 876 877 881 883 884 889 892 894 897 899 902 906 912 915 916 916 916 918 919 920 921 922 922 927 935 937 937 939 939 940 950 953 954 959 960 960 962 964 974 974 978 992 993 994 998 1004 1008 1012 1013 1014 1016 1017 1017 1018 

9. Для списков list1 и list2 из списка с большим числом элементов удалите первые n так, чтобы оба списка имели бы одинаковый размер. Сформируйте из них список list3, который будет хранить пары <первый элемент списка list1, первый элемент списка list2>, <второй элемент списка list1, второй элемент списка list2> и т. д.
<994, 28>, <993, 38>, <992, 40>, <990, 52>, <989, 54>, <989, 56>, <988, 56>, <988, 64>, <986, 66>, <981, 82>, <978, 106>, <978, 106>, <974, 108>, <974, 108>, <973, 142>, <968, 146>, <966, 146>, <965, 148>, <1024, 176>, <1018, 184>, <1018, 198>, 

10. Решите предыдущую задачу для векторов v1 и v2 без предварительного приведения векторов к одному размеру. Пар с пустыми значениями быть не должно.
<5, 213>, <7, 215>, <12, 219>, <13, 224>, <13, 230>, <14, 231>, <16, 234>, <26, 235>, <27, 245>, <27, 248>, <28, 264>, <28, 269>, <29, 274>, <29, 279>, <30, 281>, <33, 282>, <33, 291>, <38, 295>, <39, 298>, <40, 315>, <42, 322>, <45, 341>, <48, 341>, <51, 342>, <52, 343>, <53, 343>, <53, 349>, <54, 351>, <55, 352>, <55, 357>, <56, 369>, <56, 372>, <57, 375>, <62, 381>, <64, 392>, <65, 394>, <66, 399>, <68, 400>, <71, 403>, <72, 411>, <75, 412>, <77, 418>, <77, 439>, <79, 443>, <82, 448>, <86, 451>, <87, 458>, <90, 471>, <91, 471>, <91, 474>, <91, 491>, <95, 494>, <96, 495>, <97, 496>, <97, 498>, <98, 498>, <101, 501>, <103, 507>, <105, 514>, <105, 515>, <105, 516>, <105, 523>, <106, 523>, <106, 527>, <106, 534>, <108, 535>, <108, 549>, <110, 553>, <111, 557>, <117, 561>, <120, 563>, <121, 564>, <121, 571>, <123, 574>, <124, 590>, <128, 590>, <133, 608>, <135, 613>, <137, 624>, <138, 624>, <141, 632>, <142, 644>, <142, 646>, <146, 650>, <146, 652>, <147, 653>, <148, 658>, <151, 661>, <151, 671>, <154, 672>, <154, 674>, <157, 679>, <157, 681>, <158, 684>, <159, 687>, <159, 690>, <164, 694>, <165, 698>, <175, 706>, <176, 706>, <184, 718>, <186, 719>, <187, 722>, <189, 729>, <192, 729>, <193, 732>, <193, 742>, <194, 747>, <198, 749>, <199, 753>, <200, 755>, <202, 756>, <203, 757>, <205, 784>, <207, 791>, <212, 806>, <213, 817>, <215, 824>, <216, 828>, <216, 848>, <219, 858>, <219, 864>, <221, 874>, <222, 892>, <223, 899>, <223, 916>, <224, 916>, <228, 916>, <230, 920>, <230, 921>, <231, 922>, <234, 927>, <234, 950>, <234, 953>, <235, 954>, <236, 960>, <238, 974>, <239, 974>, <245, 978>, <246, 992>, <248, 993>, <248, 994>, <251, 998>, <255, 1004>, <255, 1008>, <257, 1012>, <258, 1013>, <260, 1014>, <261, 1016>, <264, 1017>, <266, 1017>, <269, 1018>, 
```