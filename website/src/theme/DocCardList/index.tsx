import React, {type ReactNode} from 'react';
import DocCardList from '@theme-original/DocCardList';
import type DocCardListType from '@theme/DocCardList';
import type {WrapperProps} from '@docusaurus/types';
import { useCurrentSidebarSiblings, filterDocCardListItems } from "@docusaurus/plugin-content-docs/client";

type Props = WrapperProps<typeof DocCardListType>;

export default function DocCardListWrapper(props: Props): ReactNode {
  const items = (useCurrentSidebarSiblings() as any[]).filter((s)=> s.docId != "index");
  
  return (
    <>
      <DocCardList {...props} items={items} />
    </>
  );
}
