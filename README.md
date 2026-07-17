<h1>General List</h1>
Library for C/C++ that adds linked list functionality.

It was originally designed for the Sprig Engine but I found it useful for other projects too.

<h2>Functions</h2>
<ul>
  <li>InitializeList
    <br>
    <ul>
      <li>
        Sets up the default values
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to GeneralList</li>
        </ol>
      </li>    
    </ul>
  </li>
  
  <li>PushList
    <br>
    <ul>
      <li>
        Appends an element to the list
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to GeneralList</li>
          <li>(void*) Pointer to data to append to list</li>
        </ol>
      </li>    
    </ul>
  </li>

  <li>PopList
    <br>
    <ul>
      <li>
        Pops last element from list
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to GeneralList</li>
        </ol>
      </li>
      <li>
        Returns:
        <ul>
          <li>(void*) Pointer to data</li>
        </ul>
      </li>
    </ul>
  </li>

  <li>PopListFirst
    <br>
    <ul>
      <li>
        Pops first element from list
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to GeneralList</li>
        </ol>
      </li>
      <li>
        Returns:
        <ul>
          <li>(void*) Pointer to data</li>
        </ul>
      </li>
    </ul>
  </li>

  <li>ListGetIndex
    <br>
    <ul>
      <li>
        Retrieves data at an index
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to GeneralList</li>
          <li>(int) Element index</li>
        </ol>
      </li>
      <li>
        Returns:
        <ul>
          <li>(void*) Pointer to data</li>
        </ul>
      </li>
    </ul>
  </li>

  <li>DeleteListElement
    <br>
    <ul>
      <li>
        Deletes an element from the list
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to GeneralList</li>
          <li>(int) Element index</li>
        </ol>
      </li>
      <li>
        Returns:
        <ul>
          <li>(void*) Pointer to data</li>
        </ul>
      </li>
      <li>
      --WARNING--
        while the element is deleted, the data is not freed. The data must be freed with free() to prevent memory leaks
      </li>
    </ul>
  </li>

  <li>TransferList
    <br>
    <ul>
      <li>
        Deletes all elements from a source list and pushes the data to a destination list in the same order
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to Destination GeneralList</li>
          <li>(GeneralList*) Pointer to Source GeneralList</li>
        </ol>
      </li>
    </ul>
  </li>

  <li>CpyList
    <br>
    <ul>
      <li>
        Copies every element from a source list to a destination list. The data is appended.
      </li>
      <li>
        Parameters:
        <ol>
          <li>(GeneralList*) Pointer to Destination GeneralList</li>
          <li>(GeneralList*) Pointer to Source GeneralList</li>
          <li>(size_t) Size of the content of each element of the source list</li>
        </ol>
      </li>
    </ul>
  </li>
</ul>


<h2>Structures</h2>
<ul>
  <li>GeneralList
    <br>
    <ul>
      <li>
        A list object
      </li>
      <li>
        Variables:
        <ol>
          <li>(GeneralListNode*) firstElement: Pointer to the first element in the list</li>
          <li>(GeneralListNode*) lastElement: Pointer to the last element in the list</li>
          <li>(int) count: number of elements in the list</li>
        </ol>
      </li>    
    </ul>
  </li>
  <li>GeneralListNode
    <br>
    <ul>
      <li>
        An element of the linked list.
      </li>
      <li>
        Variables:
        <ol>
          <li>(GeneralListNode*) next: Pointer to the next element in the list</li>
          <li>(GeneralListNode*) previous: Pointer to the previous element in the list</li>
          <li>(void*) content: pointer to the data that the element contains</li>
        </ol>
      </li>    
    </ul>
  </li>
</ul>
