import React, { type ReactNode } from "react";
import clsx from "clsx";
import Link from "@docusaurus/Link";
import { useDocById, findFirstSidebarItemLink } from "@docusaurus/plugin-content-docs/client";
import { usePluralForm } from "@docusaurus/theme-common";
import isInternalUrl from "@docusaurus/isInternalUrl";
import { translate } from "@docusaurus/Translate";

import type { Props } from "@theme/DocCard";
import Heading from "@theme/Heading";
import type { PropSidebarItemCategory, PropSidebarItemLink } from "@docusaurus/plugin-content-docs";

import styles from "./styles.module.css";
import { Button, Card } from "@mui/material";

function useCategoryItemsPlural() {
  const { selectMessage } = usePluralForm();
  return (count: number) =>
    selectMessage(
      count,
      translate(
        {
          message: "1 item|{count} items",
          id: "theme.docs.DocCard.categoryDescription.plurals",
          description: "The default description for a category card in the generated index about how many items this category includes",
        },
        { count }
      )
    );
}

function CardContainer({ className, href, children }: { className?: string; href: string; children: ReactNode }): ReactNode {
  return (
    <Button variant="outlined" sx={{textTransform:"none", textAlign: "inherit"}}>
      <Link href={href} style={{textDecoration: "none"}}>{children}</Link>
    </Button>
  );
}

function CardLayout({
  className,
  href,
  icon,
  title,
  description,
}: {
  className?: string;
  href: string;
  icon: ReactNode;
  title: string;
  description?: string;
}): ReactNode {
  return (
    <CardContainer href={href} className={className}>
      <Heading as="h2" className={clsx("text--truncate", styles.cardTitle)} title={title}>
        {icon} {title}
      </Heading>
      {description && (
        <p className={clsx("text--truncate", styles.cardDescription)} title={description}>
          {description}
        </p>
      )}
    </CardContainer>
  );
}

function CardCategory({ item }: { item: PropSidebarItemCategory }): ReactNode {
  const href = findFirstSidebarItemLink(item);
  const categoryItemsPlural = useCategoryItemsPlural();

  // Unexpected: categories that don't have a link have been filtered upfront
  if (!href) {
    return null;
  }

  return (
    <CardLayout
      className={item.className}
      href={href}
      icon="🗃️"
      title={item.label}
      description={item.description ?? categoryItemsPlural(item.items.length)}
    />
  );
}

function CardLink({ item }: { item: PropSidebarItemLink }): ReactNode {
  const icon = isInternalUrl(item.href) ? "📄️" : "🔗";
  const doc = useDocById(item.docId ?? undefined);
  return <CardLayout className={item.className} href={item.href} icon={icon} title={item.label} description={item.description ?? doc?.description} />;
}

export default function DocCard({ item }: Props): ReactNode {
  switch (item.type) {
    case "link":
      return <CardLink item={item} />;
    case "category":
      return <CardCategory item={item} />;
    default:
      throw new Error(`unknown item type ${JSON.stringify(item)}`);
  }
}
